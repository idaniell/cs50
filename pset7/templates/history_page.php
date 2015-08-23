<?php require("../includes/links.php"); ?>
<h2 style="margin-left: 10px"><?= $title ?></h2>
<table style="margin-left:auto; margin-right:auto">
   <th>
    <tr>
        <td>Type:&nbsp;</td>
        <td>Date:&nbsp; </td>
        <td>Shares:&nbsp; </td>
        <td>Price:&nbsp; </td>
        <td>Symbol:&nbsp; </td>
    </tr>
   </th>
    <?php foreach($rows as $row): ?>
         <tr>
           <td style="padding-right: 10px"><?= $row["type"]   ?></td>
           <td style="padding-right: 10px"><?= $row["date"] ?></td>
           <td style="padding-right: 10px"><?= $row["shares"] ?></td>
           <td style="padding-right: 10px"><?= money_format('$%i',($row["price"] * number_format($row["price"],2))) ?></td>
           <td><?= $row["stock symbol"] ?></td>
         </tr>  
    <?php endforeach ?>        
</table>