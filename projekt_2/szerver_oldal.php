<?php
/*function alakit($element) {
    $new = '';
    $numbers = array(5, -14, 31, -9, 3);
    $counter = 0;
    $i = 0;
    while (isset($element[$i])) {
        $ascii = ord($element[$i]);
        
        switch ($counter) {
            case 0:
                $ascii -= $numbers[$counter];
                $counter++;
                $new .= chr($ascii);
                break;
            case 1:
                $ascii -= $numbers[$counter];
                $counter++;
                $new .= chr($ascii);
                break;
            case 2:
                $ascii -= $numbers[$counter];
                echo $new
                $counter++;
                $new .= chr($ascii);
                break;
            case 3:
                $ascii -= $numbers[$counter];
                $counter++;
                $new .= chr($ascii);
                break;
            case 4:
                $ascii -= $numbers[$counter];
                $counter = 0;
                $new .= chr($ascii);
                break;
        }
        
        $i++;
    }
    
    return $new;
}*/

function alakit($element) {
    $new = '';
    $numbers = array(5,-14,31,-9,3);
    $counter = 0;
    foreach (str_split($element) as $char) {
        //$ascii = ord($char);
        
        switch ($counter) {
            case 0:
                $ascii = ord($char) - $numbers[$counter];
                $counter++;
                $new .= chr($ascii);
                break;
            case 1:
                $ascii = ord($char) - $numbers[$counter];
                $counter++;
                $new .= chr($ascii);
                break;
            case 2:
                $ascii = ord($char) - $numbers[$counter];
                $counter++;
                $new .= chr($ascii);
                break;
            case 3:
                $ascii = ord($char) - $numbers[$counter];
                $counter++;
                $new .= chr($ascii);
                break;
            case 4:
                $ascii = ord($char) - $numbers[$counter];
                $counter = 0;
                $new .= chr($ascii);
                break;
        }
    }
    
    return $new;
}    


/*function alakit($element, $length) {
    $new = '';
    $numbers = array(5, -14, 31, -9, 3);
    $counter = 0;
    for ($i = 0; $i < $length; $i++) {
        $ascii = ord($element[$i]);
        
        switch ($counter) {
            case 0:
                $ascii -= $numbers[$counter];
                $counter++;
                $new .= chr($ascii);
                break;
            case 1:
                $ascii -= $numbers[$counter];
                $counter++;
                $new .= chr($ascii);
                break;
            case 2:
                $ascii -= $numbers[$counter];
                $counter++;
                $new .= chr($ascii);
                break;
            case 3:
                $ascii -= $numbers[$counter];
                $counter++;
                $new .= chr($ascii);
                break;
            case 4:
                $ascii -= $numbers[$counter];
                $counter = 0;
                $new .= chr($ascii);
                break;
        }
    }
    
    return $new;
}    */
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $username = $_POST['username'];
    $password = $_POST['password'];



$file = fopen("password.txt", "r");
$found = false;

    if ($file)
    {
        while (($line = fgets($file)) !== false)
        {

        $chars = str_split($line);
        $nums = array(5, -14, 31, -9, 3);
        $i = 0;

        $end = array();

        foreach($chars as $c){
            if(ord($c) != 10) {
                $end[] = chr(ord($c) - $nums[$i % 5]);
            }
            $i++;
        }

        $ln = implode("",$end);
        $pieces = explode("*", $ln);
        echo $pieces[0], " : ", $pieces[1], "<br>";
        }
    }



    // A password.txt fájl beolvasása és a felhasználónév-jelszó párok ellenőrzése
    /*$file = fopen('password.txt', 'r');
    $found = false;
    while (!feof($file)) {
        $line = trim(fgets($file));
        $line = alakit($line);//, strlen($line));
        echo '<p>' .$line . '</p>' . PHP_EOL ;
        if (strpos($line, $username . '*') === 0) {
            list($user, $pass) = explode('*', $line);
            //echo $user . ' ' . $pass;
            if ($pass === $password) {
                echo "Sikeres bejelentkezés! Felhasználónév: $user, Jelszó: $pass";
                $found = true;
                break;
            }
        }
    }
    fclose($file);

    if (!$found) {
        echo "Hibás felhasználónév vagy jelszó!";
    }*/
}
?>
