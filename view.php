<?php
require 'funcdefs.php';
?><html>
<head>
	<title>kawaii</title>
	<link rel="stylesheet" type="text/css" href="style.css" />  
</head>
<body>
<form id="voteform" method="post">
</form>
	<?php 
	 if(isset($_POST['voted']) and isset($_GET['index']) and $sec=checksec($_COOKIE["uindex"],$_COOKIE["hash"])){
    addvote($_GET['index'],$_POST['voted']);
  }elseif($sec==false and isset($_POST['voted'])){
    printError("You are not logged in.");
  }
	
  if(isset($_POST['user_comment']) and checksec($_COOKIE["uindex"],$_COOKIE["hash"])){
    addcomment($_GET['index'],$_POST['user_comment']);
  }elseif(checksec($_COOKIE["uindex"],$_COOKIE["hash"])==false and isset($_POST['user_comment'])){
    printError("You are not logged in.");
  }
?>
<?php if (isset($_GET['index'])): ?>
   <?php viewpage($_GET['index'],!isset($_POST['voted'])); ?>
     <?php echo '<form method="post" action="./view.php?index='.$_GET['index'].'">'; ?> 
     <h3>Add a comment</h3>
      <input type="text" name="user_comment" placeholder="add a comment" />
      <br>
      <button type="submit">Submit</button>
    </form>
<?php endif; ?>
</body>
</html>
