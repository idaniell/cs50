<span> NAME: </span> |  <span> SYMBOL: </span> | <span> PRICE: </span>
<div>
<div style = "display: inline-block"> <?php echo $name; ?> </div>
<div style = "display: inline-block"> <?php echo $symbol; ?></div> 
<div style = "display: inline-block"> <?php echo number_format($price,2); ?></div> 
</div>

<form action="buy.php" method="post">
   <fieldset>
    <div class="form-group">
       <input type="text" name="shares" placeholder="Enter amt of shares"></input>
    </div>
    <input type="hidden" name="price" value="<?php echo number_format($price,2); ?>"/>
    <input type="hidden" name="symbol" value="<?php echo $symbol; ?>"/>
    <div class="form-group">
        <button type="submit" class="btn btn-default">Buy</button>
    </div>
   </fieldset>
</form>
