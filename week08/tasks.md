# УП практикум - задачи за 24.11.2023

## Задача 1

Да се напише програма, която по въведен от потребителя масив с цели числа, число **p** и число **r**, заменя всички срещания на числото **p** в масива с числото **r**.

*Допълнение*: Модифицирайте програмата, така че да работи с дробни числа. Използвайте сравнения с точност $10^{-5}$

## Задача 2

Напишете програма, която да трие елемент с индекс **k** от масив с $n <= 100$ на брой положителни числа и да измества другите елементи, като в получилaтa се дупка сложите числото -1, което бележи, че e невалиднo поле. Входът се състои от числото n, последвано от n числа и накрая се въвежда k.

Вход:

    5
    3 7 23 5 1
    2

Изход:

    3 7 5 1 -1

## Задача 2А

Как ще модифицирате решението си на задача 2, така че въвеждането на масива да приключва при подаване на символа `#`, вместо броят на числата да се въвежда предварително? Приемете, че числата ще бъдат едноцифрени.

## Задача 3

Тъй като Мишо не се справя с ФМИ и само кисне по дискотеките, майка му решила да го накаже като му спре мобилния интернет. Мишо не е особено очарован от идеята, но какво да прави... Става още по-лошо защото приятелите му организират дискотека и на него му трябва интернет за да се разберат къде ще се срещат. Той има следния план: Знае позициите на рутерите в баровете, където е бил и тяхното покритие. Както знае и точките в които ще бъде през деня. Напишете програма която по дадени рутери с място и покритие и точки в които ще е Мишо, определя дали ще има интернет от тях и ако има извежда „Happy Misho“, ако не – „Sad Misho“.

Вход:

    3
    0 0 2
    2 2 3
    -1 -1 2
    2
    1 1
    4 3

Изход:

    Happy Misho

Вход:

    3
    0 0 2
    2 2 3
    -1 -1 2
    3
    1 1
    4 3
    7 7

Изход:

    Sad Misho

## Задача 4

Напишете програма, която приема масив с $N <= 1000$ елемента, всеки от които е индекс на елемент, т.е. е естествено число между 0 и N. Програмата да приеме още два индекса и за всеки от тях да изведе цялата редица, започваща от него и определена по следния начин:

- следващият елемент се намира на индекса, равен на стойността на настоящия елемент
- при достигане на цикъл, т.е. щом едни и същи индекси започнат да се повтарят, извеждането на редицата спира.

Примерен вход:

    5
    2 1 4 3 2
    0 1

Примерен изход:

    2 4 2
    1

## Задача 5

Напишете програма, която приема масив с $N <= 255$ цели числа в интервала от 0 до 4 000 000 000 и го извежда сортиран във възходящ ред.

## Задача 6

Напишете програма, която приема $N <= 4 000 000 000$ цели числа в интервала от 0 до 255 и ги извежда сортирани във възходящ ред. Забележете разликите и приликата с предната задача и се опитайте да измислите много по-добър от предния, специфичен алгоритъм, който да може да работи в реално време.

## Задача 7

Напишете програма, която:

- приема естествено число $N <= 30$, последвано от N-те реда на квадратна матрица от естествени числа с NxN елемента;
- умножава всяко число по номера на неговия ред и го увеличава с номера на колоната му;
- извежда променената матрица на нови N реда.

## Задача 8

Да се напише функция, която като параметри получава матрица с размери **N** x **M** и резултатна матрица. Функцията да записва във втората матрица резултатът от транспонирането на първата матрица.

## Задача 9

Напишете програма, която приема квадратна матрица от реални числа с размер $N <= 30$ и извежда нейния квадрат.

## Задача 10

Да се напише програма, която въвежда квадратна матрица с размери **n** x **n**  от цели числа и използва функция, за да провери дали матрицата е "магически квадрат" (сумите по редовете и стълбовете да са равни).

Вход:

    3
    1 1 1
    1 1 1
    1 1 1

Изход:

    Magic

Вход:

    3
    1 2 3
    3 2 1
    2 3 1

Изход:

    Normal
