<?php
// includes 
require("../includes/config.php"); 

if ($_SERVER["REQUEST_METHOD"] == "GET")
{
    $user = $_SESSION["id"];
    $rows = query("SELECT * FROM `history` WHERE id = (?)",$user);

    render("history_page.php", ["rows" => $rows, "title" => "Account History"]);
}

?>
