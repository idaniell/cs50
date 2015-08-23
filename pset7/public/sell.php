<?php
// includes 
require("../includes/config.php"); 

// portfolio
if($_SESSION["id"] !== NULL)
{
    if($_SERVER["REQUEST_METHOD"] == "GET")
    {
        $user = $_SESSION["id"];
        $stocks = query("SELECT `symbol` FROM `Portfolio` WHERE id = (?)", $user);
        $current_cash = query("SELECT `cash` FROM `users` WHERE id = (?)", $user);

        render("sell_form.php", ["stocks" => $stocks, "cash_balance" => $current_cash, "title" => "SELL!!!"]);
    }
    else if($_SERVER["REQUEST_METHOD"] == "POST")
    {
        $user = $_SESSION["id"];
        $sold = $_POST['soldPosition'];
        $result = lookup($sold);
        $getPrice = $result["price"];
        $ticker = $result["symbol"];
        if($result == 0 || $result == null || $result = '')
        {
            apologize("Position wasn't found in portfolio");
        }
        else
        {
            $shares = query("SELECT `shares` FROM `Portfolio` WHERE id = (?) AND symbol = (?)",$user,$sold);
            $total = $getPrice * $shares[0]["shares"];
            if(($total !== 0 || $total !== null) && $shares[0]["shares"] > 0){
                $proceeds = query("UPDATE users SET cash = cash + (?) WHERE id = (?)",$total,$user);
                $removal = query("DELETE FROM `Portfolio` WHERE id = (?) AND symbol = (?)", $user, $ticker);
                $history = query("INSERT INTO `history`(`id`, `type`, `date`, `shares`, `price`, `stock symbol`) VALUES ((?),(?),NOW(),(?),(?),(?))", $user,"SELL",$shares[0]["shares"],$getPrice,$ticker);
                if($proceeds !== false && $removal !== false && $history !== false)
                {
                    redirect("index.php");   
                }
            }
            else
            {
                apologize("An error occured. Please retry");
            }
        }
    }
}
?>
