# УП практикум - задачи за 17.11.2023

За краткост, когато в условията се казва, че програма приема масив с N числа (от някакъв тип), се има предвид, че тя:
1. Чете от стандартния вход естествено число N.
2. След това чете от стандартния вход N числа от съответния тип и ги записва в масив от същия тип, достатъчно голям да ги побере.

## Задача 1

Напишете програма, която приема масив с $N <= 1000$ цели числа и:
- ги извежда в обратен ред;
- намира най-малкото от тях и го извежда заедно с индекса му (в правия ред).

## Задача 2

Напишете програма за търсене и броене, която приема масив с $N <= 1000$ реални числа и още едно реално число `r` и
извежда колко пъти `r` се среща в масива с точност 3 знака след десетичната запетая.

Пример: 5 1 1.5 1.05 1.005 1.0005 1 -> 2

## Задача 3

Ще наричаме редицата от числа $N_1, N_2, ... N_n$ зигзагообразно нарастваща, ако всеки неин четен елемент е по-голям от предходните два,
а всеки нечетен е по-малък от предходния, т.е. ако

$$
\begin{cases}
  N_i > N_{i-1}, \quad i \bmod 2 = 0\\
  N_i > N_{i-2}, \quad i \bmod 2 = 0 \land i >= 4\\
  N_i < N_{i-1}, \quad i \bmod 2 = 1 \land i >= 3\\
\end{cases}
$$

Напишете програма, която приема масив с $N <= 1000$ числа от тип по ваш избор и извежда дали въведените числа представляват
зигзагообразно нарастваща редица. Ако не, да се изведе и индексът (0-based, т.е. започвайки от 0) на първото нарушение на правилото.

Примери:
- 1 3 2 4 3 7 -> true
- 1 3 4 5 -> false, 2
- 1 3 2 3 -> false, 3
- 1 3 2 3 2 3 2 3 -> false, 3

## Задача 4

Когато искаме многократно да проверяваме дали различни числа, неизвестни предварително, са прости, не е много ефективно всеки път
да обхождаме всички техни потенциални делители (дори и ако оптимизираме обхождането, като го правим само до корена на числото,
което искаме да проверим). Много по-добре е например да си конструираме предварително един вид решето на Ератостен и след това
да проверяваме в него. Решетото на Ератостен работи по следния начин:
- започваме от числото `n = 2`
- задраскваме всички числа, кратни на `n` (т.е. в началото 2, 4, 6, 8 и т.н.)
- търсим следващия `n` - първото по-голямо число, което все още не е задраскано;
в случая с 2 това ще е 3, но в случая със 7 ще е чак 11.

Напишете програма, която приема 2 естествени числа, не по-големи от 10 000, и извежда за всяко от тях дали е просто,
като за проверката използва решето на Ератостен.

## Задача 5

Модифицирайте решението си на задача 4, така че да приема масив с $N <= 1000$ естествени числа, не по-големи от 100 000,
и за всяко от тях да извежда дали е просто.