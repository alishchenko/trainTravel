# trainTravel
Дано расписание переездов поездов между несколькими станциями. Необходимо получить “лучшие” варианты проезда между всеми станциями так чтобы побывать на каждой станции 1 раз.
 - Лучшие по цене
 - Лучшие по времени (ожидание на вокзале не учитывается)

Так как на каждой станции следует побывать всего один раз, нахождение Гамильтова цикла (проход по всем точкам графа с возвращением в первоначальную) в этом случае не подходит. Поэтому классический комивояжер сюда не подойдет.

Алгоритм заключается в том чтобы найти все Гамильтоновы пути, а затем выбрать все минимальные по определенным критериям.

