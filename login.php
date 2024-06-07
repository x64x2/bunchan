<?php
require 'funcdefs.php';
if (isset($_POST['luser']) and isset($_POST['lpassword'])){
  verifylogin($_POST['luser'],$_POST['lpassword']);
}
?><html>
<head>
	<title>3ga - login</title>
	<link rel="stylesheet" type="text/css" href="style.css" />  
</head>
<body>
  <?php if(empty($_POST)): ?>
	   <h3>Logín</h3>
      <form method="post" action="./login.php">
      <input type="text" name="luser" placeholder="username" />
      <br />
      <input type="password" name="lpassword" placeholder="password" />
      <br>
      <button type="submit">Login</button>
    </form>
  <?php endif;?>
</body>
</html>
