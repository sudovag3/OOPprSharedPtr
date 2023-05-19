## Задача 1

Представить пример кода,где экземпляры shared_ptr владеют одним объектом.

### Теоретическая справка

std::shared_ptr является одним из умных указателей (smart pointer) в стандартной библиотеке C++. Он предоставляет автоматическое управление памятью для объектов в динамической памяти и реализует подсчет ссылок (reference counting) для определения времени жизни объекта. Когда количество ссылок на объект становится равным нулю, память автоматически освобождается.

## Задача 2
Пояснить и привести пример для чего используется:
- функция-член use_count; (task2.1.cpp)
- функция член unique; (task2.2.cpp)
- функция-член swap; (task2.3.cpp)
- функция-член reset. (task2.4.cpp)

## Задача 3.1

- Предложить пример кода, где два объекта shared_ptr ссылаются друг на друга(циклическая ссылка).
  Решение - task3.1.cpp

### Теоретическая справка

В этом примере создаются два объекта std::shared_ptr: myClassPtr и otherClassPtr, которые ссылаются друг на друга. myClassPtr содержит указатель на объект класса OtherClass, а otherClassPtr содержит указатель на объект класса MyClass. Это создает циклическую ссылку между объектами.

Однако, когда программа пытается освободить память и удалить объекты, она сталкивается с проблемой циклической ссылки. Оба shared_ptr имеют счетчик ссылок, равный 1, но ни один из них не может уменьшить счетчик ссылок объекта до 0, чтобы освободить память. В результате объекты не будут корректно удалены, и произойдет утечка памяти.

## Задача 3.2

Как решается проблема циклических ссылок? Предложите пример.
 Решение - task.3.2.cpp

### Теоретическая справка

Проблема циклических ссылок между std::shared_ptr может быть решена с использованием std::weak_ptr. std::weak_ptr позволяет создавать слабые ссылки на объекты, не увеличивая счетчик ссылок и не влияя на время жизни объекта.