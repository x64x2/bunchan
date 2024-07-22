<?php
require 'foo.php';
?><html>
<head>
	<title>kawaii- registration</title>
	<link rel="stylesheet" type="text/css" href="style.css" />  
</head>
<body>
  <?php if(empty($_POST)): ?>
	   <h3>Registration</h3>
    <form method="post" action="./register.php">
      <input type="text" name="nuser" placeholder="username" />
      <br />
      <input type="password" name="npassword" placeholder="pwd" />
      <br>
      <button name="action" value="register">Send</button>
    </form>
  <?php elseif(isset($_POST['nuser']) and isset($_POST['npassword'])): ?>
    <?php newuser($_POST['nuser'],$_POST['npassword']); ?>
  <?php endif; ?>
</body>
</html>

</body>
</html>
