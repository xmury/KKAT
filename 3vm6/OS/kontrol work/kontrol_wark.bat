rem Контрольная работа по теме "OS MS DOS"
cd D:\
md NOV
cd NOV
md BOX
cd BOX
copy con mytext.txt
    Ability to be quided at the boundless
    ocean of information and to use it the activity
    distinguishes the modern educated person
copy con ..\Paket.bat
    dir D:\ /w > D:\NOV\BOX\First.txt
    dir C:\ /O:S > D:\NOV\Serch.txt
    find "ocean of information" .\BOX\mytext.txt > D:\NOV\BOX\Third.txt
    cd D:\NOV\BOX\
    fc mytext.txt Third.txt > D:\NOV\Comp.txt
    cd ..
    type Comp.txt
    copy D:\NOV\BOX\First.txt + D:\NOV\Serch.txt D:\NOV\Plus.txt
    rmdir /S BOX
    ren NOV Stepanuk
cd D:\NOV\
Paket.bat
copy con AUTO.txt
    1.1 Set    -> вывод, задание и удаление переменных среды cmd.exe
	1.2 Path   -> вывод или задание путей поиска исполняемых файлов
	1.3 Prompt -> Изменение приглашения командной строки cmd.exe

copy con SYS.txt
    2.1 Device  -> установка драйверов устройства
	2.2 Files   -> установка максимального числа открытых в ОС файлов
	2.3 Country -> настройка параметров соответствующих стране
	2.4 Mscdex  -> количество буферов для встроенного кэша ОС
	2.5 Stacks  -> количество стеков для аппаратных прерываний
md PROBA
copy AUTO.txt + SYS.txt PROBA\COMFILES.txt
