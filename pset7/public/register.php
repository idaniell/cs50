<?php

require("../includes/config.php");

if($_SERVER["REQUEST_METHOD"] == "GET")
{
    render("register_form.php", ["title" =>"Register"]);
}
else if($_SERVER["REQUEST_METHOD"] == "POST")
{
    if((empty($_POST["username"]) || empty($_POST["password"]) || empty($_POST["confirmation"]) || empty($_POST["email"])) || ($_POST["password"] !== $_POST["confirmation"]))
    {
        apologize("Something went wrong during save. Try it again.");
    }
    else{

        $result = query("INSERT INTO `users`(`username`, `hash`, `cash`, `email`) VALUES ((?),(?),10000.00,(?))",$_POST["username"],crypt($_POST["password"]),$_POST["email"]);
        if($result === false)
        {
            apologize("Couldn't be saved to database");
        }
        else
            $msg = "Thanks for signing up!";
        mail($_POST["email"],"Thanks for signing up",$msg);
        $rows = query("SELECT LAST_INSERT_ID() AS id");
        $id = $rows[0]["id"];
        $_SESSION["id"] = $id;  
        redirect("index.php");   
    }

}
?>
