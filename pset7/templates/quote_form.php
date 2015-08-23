<h2><?php echo $title ?></h2>

<form action="quote.php" method="post">
 <fieldset>
    <div class="form-group">
        <input class="form-control" type="text" name="symbol" placeholder="Enter a valid stock symbol"/>
    </div>
    <div class="form-group">
        <button type="submit" class="btn btn-default">Submit it</button>
    </div>
 </fieldset>
</form>
