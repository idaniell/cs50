<?php require("../includes/links.php"); ?>
<h3><?= $title ?></h3>
<form action="quote.php" method="post">
   <fieldset>
    <div class="form-group">
       <input type="text" name="symbol" autofocus required placeholder="Enter a symbol to buy"/>
    </div>
    <div class="form-group">
        <button type="submit" class="btn btn-default">Buy it</button>
    </div>
   </fieldset>
</form>
