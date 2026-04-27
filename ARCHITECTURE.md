# Архитектура проекта `oop-1lab`

## 1) Назначение
Консольное приложение для работы с геометрическими фигурами (`Circle`, `Rectangle`, `Triangle`) в общей коллекции.

---

## 2) Слои и роли

### Точка входа / композиция зависимостей
- **`main.cpp`**
  - Создаёт основные объекты приложения.
  - Связывает зависимости между ними.
  - Запускает цикл меню.

Создаваемые объекты:
1. `ShapeManager` — хранение и операции над коллекцией фигур.
2. `ShapeFactory` — создание конкретных фигур.
3. `Input` — чтение данных из консоли.
4. `Output` — вывод меню/сообщений/списков.
5. `ShapeAdder` — сценарий добавления фигуры (ввод + создание + сохранение).
6. `Menu` — основной сценарий работы пользователя.

---

### Доменная модель
- **`Shape`** (`shape.h/.cpp`) — абстрактная базовая фигура:
  - `getPerimeter()`
  - `toString()`
- **`Circle`**, **`Rectangle`**, **`Triangle`** — конкретные фигуры:
  - хранят только свои параметры;
  - в конструкторах валидируют корректность;
  - бросают доменные исключения при ошибках.
- **`Point`** (`point.h/.cpp`) — простая структура точки (`x`, `y`) + геттеры.

---

### Сервисный слой
- **`ShapeManager`** (`shape_manager.h/.cpp`)
  - владеет `std::vector<std::shared_ptr<Shape>>`;
  - добавление, удаление, сортировка;
  - вычисление суммы периметров.
- **`ShapeFactory`** (`shape_factory.h/.cpp`)
  - создаёт `Circle`/`Rectangle`/`Triangle`;
  - возвращает `std::shared_ptr<Shape>`.

---

### Слой сценариев (application flow)
- **`Menu`** (`menu.h/.cpp`)
  - отображает пользовательское меню;
  - маршрутизирует команды пользователя;
  - вызывает `ShapeManager` и `ShapeAdder`.
- **`ShapeAdder`** (`shape_adder.h/.cpp`)
  - спрашивает тип фигуры и параметры;
  - делегирует создание в `ShapeFactory`;
  - передаёт готовый объект в `ShapeManager`.

---

### Инфраструктура ввода/вывода
- **`Input`** (`input.h/.cpp`) — безопасное чтение `int/double/string`.
- **`Output`** (`output.h/.cpp`) — вывод меню, сообщений и отчётов.

---

### Обработка ошибок
- **`ShapeException`** и наследники (`exceptions.h/.cpp`):
  - `InvalidFigureException`
  - `DegenerateFigureException`
- Исключения выбрасываются в конструкторах фигур и перехватываются в `Menu::run()`.

---

## 3) Связи между компонентами

## Композиция зависимостей
`main` -> создаёт и связывает:
- `Menu(ShapeManager&, Input&, Output&, ShapeAdder&)`
- `ShapeAdder(ShapeManager&, ShapeFactory&, Input&, Output&)`

## Использование в рантайме
- `Menu` использует:
  - `Input` (чтение выбора)
  - `Output` (вывод)
  - `ShapeManager` (операции коллекции)
  - `ShapeAdder` (добавление фигуры)
- `ShapeAdder` использует:
  - `Input`/`Output` (диалог)
  - `ShapeFactory` (создание фигуры)
  - `ShapeManager` (сохранение)
- `ShapeFactory` создаёт объекты, наследующие `Shape`.
- `ShapeManager` работает с полиморфной коллекцией `Shape`.

---

## 4) Типовой сценарий взаимодействия (добавление фигуры)
1. Пользователь выбирает пункт **1** в `Menu`.
2. `Menu` вызывает `ShapeAdder::addShape()`.
3. `ShapeAdder` читает тип и параметры через `Input`.
4. `ShapeAdder` вызывает нужный метод `ShapeFactory`.
5. `ShapeFactory` создаёт конкретную фигуру (`Circle/Rectangle/Triangle`).
6. При невалидных параметрах конструктор бросает исключение.
7. `Menu::run()` перехватывает `ShapeException` и показывает ошибку через `Output`.
8. При успехе `ShapeAdder` передаёт фигуру в `ShapeManager::addShape()`.

---

## 5) Граф зависимостей (упрощённо)

```text
main
 ├─> ShapeManager
 ├─> ShapeFactory
 ├─> Input
 ├─> Output
 ├─> ShapeAdder ── uses ──> ShapeFactory
 │         │
 │         └── uses ─────> ShapeManager
 └─> Menu ───────────────> ShapeAdder
           ├─────────────> ShapeManager
           ├─────────────> Input
           └─────────────> Output

ShapeFactory ── creates ──> Circle / Rectangle / Triangle
Circle/Rectangle/Triangle ── inherit ──> Shape
ShapeManager ── stores ──> shared_ptr<Shape>
```

---

## 6) Почему такая архитектура полезна
- **Разделение ответственности**:
  - управление коллекцией != создание фигур != UI-диалог.
- **Расширяемость**:
  - добавление новой фигуры обычно затрагивает `Shape`, новую реализацию, `ShapeFactory`, и пункт в `ShapeAdder`.
- **Поддерживаемость**:
  - проще менять логику создания/валидации, не переписывая меню.
