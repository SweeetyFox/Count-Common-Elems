# Count-Common-Elems
<!---
The goal of this project was to learn how to work with *GTEST* library.
So I implemented a **function**, which optimally **counts common elements in two std::vectors** and made some tests to ensure that it works correctly.
[Funtion's implementation](https://github.com/SweeetyFox/Count-Common-Elems/blob/master/count_common_elements.cpp)
[Tests](https://github.com/SweeetyFox/Count-Common-Elems/blob/master/count_common_elements_testing.cpp)
-->
Я реализовал [функцию](https://github.com/SweeetyFox/Count-Common-Elems/blob/master/count_common_elements.cpp), которая оптимально считает колличество общих элементов в двух *std::vectors*, и сделал [тесты](https://github.com/SweeetyFox/Count-Common-Elems/blob/master/count_common_elements_testing.cpp), чтобы убедиться, что она работает корректно.
## Алгоритм
В своем алгоритме я использовал *std::unordered_set*, который реализован на хеш-таблицах. Это позволяет нам за амортизированную единицу искать в сете и добавлять в него. Мы помещаем в сет все элементы меньшего массива (чтобы сэкономить память) и проверяем на вхождение в этот сет все элементы большего массива. Время работы *O(n)*.
## Альтернативы
* Построить бор на простом разложении чисел. Т.е. каждое число раскладываем на простые множители и добавляем в бор. Ребра бора - простые числа. Потом происходит поиск числа в боре.
* Отсортировать все элементы одного из массивов и искать в нем элементы второго при помощи бин-поиска.
## Преимущества моего решения
* **Ассимтотика**. Мой алгорит работает за *O(n)*, в то время как альтернативные решения не успеют за это время даже сделать precalc: построение бора за *O(n * sqrt n)*, а сортировка массива за *O(n * log n)*
* **Читаемость кода**. Использование встроенных структур данных облегчает чтение и понимание кода. 
* **Отсутствие ошибок**. Реализация собственных структур содержит больше ошибок, влияющих на правильность работы программы и её оптимальность. Безопаснее и легче использовать уже готовые, встроенные структуры.
