# Infrastructure project 
* Build system: cmake
* Tests: gtest
* Code style check: cpplint
* Continuous integration: travis-ci

## Merging an upstream repository into your fork (master branch)
```
 git checkout master
 git pull https://github.com/alexey-sidnev/infrastructure.git master
```
## Update working branch
```
 git checkout <your branch>
 git rebase master
```
## Task
Реализовать функцию построения бинарного дерева поиска по отсортированному массиву
* Построенное дерево должно быть сбалансированным
* Время работы функции - линейное
Также необходимо реализовать Google-tests и приложение.