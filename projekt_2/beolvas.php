<?php

define("BYTE_ORDERS", array(5,-14,31,-9,3)); // a sorrend, amiben a karaktereket cserélni kell

$filename = "password.txt";
$file = fopen($filename, "r");

if (!$file) {
    die("Hiba: nem sikerült megnyitni a fájlt.");
}

$atfogo_sorok = array(); // ide tároljuk az átalakított sorokat
while (!feof($file)) {
    $sor = fgets($file); // beolvassuk a sort
    $sor = trim($sor); // eltávolítjuk a sortörést

    $byte_arr = str_split($sor); // karaktereket tömbbe szervezzük
    $new_byte_arr = array(); // ide tároljuk az átalakított sor karaktereit

    foreach (BYTE_ORDERS as $order) {
        if ($order > 0) { // balra shiftelés
            $new_byte_arr = array_merge($new_byte_arr, array_slice($byte_arr, $order));
            $new_byte_arr = array_merge($new_byte_arr, array_slice($byte_arr, 0, $order));
        } else { // jobbra shiftelés
            $new_byte_arr = array_merge($new_byte_arr, array_slice($byte_arr, $order, abs($order)));
            $new_byte_arr = array_merge($new_byte_arr, array_slice($byte_arr, 0, $order));
        }
        $byte_arr = $new_byte_arr;
        $new_byte_arr = array();
    }

    $atfogo_sorok[] = implode("", $byte_arr); // átalakított sor hozzáadása az eredmény tömbhöz
}
fclose($file);

$string1 = array();
$string2 = array();
foreach ($atfogo_sorok as $sor) {
    $idx = strpos($sor, "*"); // csillag keresése a sorban
    if ($idx !== false) { // ha találtunk csillagot
        $string1[] = substr($sor, 0, $idx); // csillag előtti rész
        $string2[] = substr($sor, $idx + 1); // csillag utáni rész
    }
}

print_r($string1); // kiírjuk az eredményeket
print_r($string2);

?>
