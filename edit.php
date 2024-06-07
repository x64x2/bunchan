<?php 
require 'foo.php';
initdb(); ?>

<html>
<head>
	<title>3ga - edit</title>
	<link rel="stylesheet" type="text/css" href="style.css" />  
</head>
<body>
   <?php if(checksec($_COOKIE["uindex"],$_COOKIE["hash"])==false): ?>
    <?php printError("you are not logged in."); ?>
	 <?php elseif(checksec($_COOKIE["uindex"],$_COOKIE["hash"]) and isset($_GET['index']) and empty($_POST) and $_GET['a']=='editpage'): ?>
   <?= '<h3>Editing page: <u>'.gettitlefromindex($_GET['index']).'</u></h3>' ?> 
   <?= '<form method="post" action="./edit.php?a=wr&index='.$_GET['index'].'">'; ?>
    <?= '<textarea name="edit_content">'.getcontent_nl2br($_GET['index']).'</textarea><br>' ?>
  <button type="submit">Send</button>
  <?php elseif(isset($_COOKIE["verified"]) and isset($_GET['index']) and !empty($_POST['edit_content']) and $_GET['a']=="wr"): ?>
     <?php editpagetext($_GET['index'],$_POST['edit_content']); ?>
     <?php elseif(isset($_COOKIE["verified"]) and isset($_GET['index']) and $_GET['a']=="viewhistory"): ?>
     <?= "<h1>Showing edit history for page: ".gettitlefromindex($_GET['index'])."</h1>" ?>
     <?php showedits($_GET['index']) ?>
  <?php endif; ?>
</form>
</body>
</html>
