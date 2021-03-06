# RAID array 

## Теория 

> **RAID** - Tехнология виртуализации данных, которая объединяет несколько дисков в логический элемент для избыточности и повышения производительности. 

Различают  несколько типов raid-массивов для разных нужд. 

#### RAID 0 
Дисковый массив из двух или более жёстких дисков без резервирования. Информация разбивается на блоки данных фиксированной длины и записывается на оба/несколько дисков поочередно

#### RAID 1 
Массив из двух ****(или более) дисков, являющихся полными копиями друг друга.

#### RAID 2 
Зарезервирован для массивов, которые применяют код Хемминга;
#### RAID 3 и RAID 4 
Дисковые массивы с чередованием и выделенным диском чётности;
#### RAID 5  
Дисковый массив с чередованием и отсутствием выделенного диска чётности.

#### RAID 6
Дисковый массив с чередованием, использующий две контрольные суммы, вычисляемые двумя независимыми способами;
#### RAID 10 
Массив RAID 0, построенный из массивов RAID 1;
#### RAID 01 
Массив RAID 1, построенный из массивов RAID 0 (имеет низкую отказоустойчивость);
> Прочие RAID 1E (зеркало из трёх устройств), RAID 50 (массив RAID 0 из массивов RAID 5), RAID 05 (RAID 5 из RAID 0), RAID 60 (RAID 0 из RAID 6) и различные другие.

### Реализации RAID массивов
- Аппаратные 
- Програмные 

## Практика

### Вспомогательные команды
- `fdisk -l` - показать имеющиеся диски и информацию о них
- `lsblk` - показать разделы, файловую систему и точку монтирования

### Создание разделов
```bash
fdisk /dev/disk_name
```
- n - создаём новый раздел
- соглашаемся с установками по умолчанию
- t - вероятно тип таблицы
- fb - тип файловой системы [ linux raid auto ]
- p - вывод предполагаемых настроек
- w - применение

### Создание RAID-массива
```bash
mdadm --create /dev/name_raid_disk --level=1 --raid-devices=2 dev/sd1 dev/sd2
```

### Разметка диска 
```bash
mkfs.ext4 /dev/name_raid_disk
``` 
### Монтирование диска
```
```bash
mount /dev/name_raid_disk /way_to_file
```

### Автомонтирование
```bash
*name_raid_disk*    **/mount_file**        *ext4*        **defaults**    0         0 
```

## Manual
- Установить пакет mdadm: `yum install mdadm -y`

### Разметка дисков
1. Разделить диск sdb на два раздела по 2.5G:
```bash
fdisk /dev/sdb
    n - создаём новый раздел
    p - основной раздел
    1 - номер раздела
    Пропуск - раздел будет начинатся с начала свободного пространства 
    +2500Mb - раздел занимает 2,5 Gb на диске 
    t - тип таблицы
    fb - тип файловой системы [ linux raid auto ]
    n
    p
    2
    Пропуск
    Пропуск - Раздел займет оставшееся место на диске
    t
    2 - выбираем второй раздел
    fb
    p - вывод предполагаемых настроек
    w - применение
```

### Создание raid-массива первого уровня
1. Просмотреть схему имеющихся дисков и разделов: `lsblk`
2. Создать raid-массив первого уровня: `mdadm --create /dev/md0 --level=1 --raid-devices=2 /dev/sdb /dev/sdc`
- Проверить статус создания массива: `cat /proc/mdstat`



### Создание raid-массива пятого уровня
1. Просмотреть схему имеющихся дисков и разделов: `lsblk`
2. Создать raid-массив первого уровня: `mdadm --create /dev/md0 --level=5 --raid-devices=3 /dev/sdb /dev/sdc /dev/sdd`
3. Проверить статус создания массива: `cat /proc/mdstat`

### Удаление массива
1. Остановить работу массива: `mdadm -S /dev/md0`
2. Очистить суперблоки на используемых дисках: `mdadm --zero-superblock /dev/sdb /dev/sdc`
