<?php

require("../includes/config.php");

if($_SERVER["REQUEST_METHOD"] == "GET")
{
    render("quote_form.php", ["title"=>"Enter a symbol"]);
}
else if($_SERVER["REQUEST_METHOD"] == "POST")
{
    if((empty($_POST["symbol"])))
    {
        apologize("Enter a symbol");
    }else{
        $s = lookup($_POST["symbol"]);
        if(($s === false)){
            apologize("Invalid symbol");
        }else{
            $price = $s["price"];
            $symbol = $s["symbol"];
            $name = $s["name"];
            render("quote_price.php",["price" =>"$price","name" => "$name","symbol"=>"$symbol"]); 
        }
    }        
}
?>
