<?php
require 'foo.php';
if (isset($_POST['luser']) and isset($_POST['lpassword'])){
  verifylogin($_POST['luser'],$_POST['lpassword']);
}
if (!isset($_POST['login'])) {
   $login = escape_data($_POST['login']);
}
if (!empty($_POST['email'])) {
	$email = escape_data($_POST['email']);
} else {
	$email = FALSE;
	$msg .= $loginphp['msg']['err_email'];
}

if (!empty($_POST['password'])) {
	$password = escape_data($_POST['password']);

} else {
	$password = FALSE;
	$msg .= $loginphp['msg']['err_password'];
}

if (! ($email && $password)) {
	$msg .= $loginphp['msg']['err_tryagain'];
}
$query = "SELECT password, powerlevel FROM $table WHERE email=?";
$result = mysqli_execute_query($dbc, $query, [$email]);
$assoc = mysqli_fetch_assoc($result);
if (!$assoc) {
	$msg .= $loginphp['msg']['err_no_email'];
}

if (password_verify($password, $assoc['password'])) {
	$msg .= $loginphp['msg']['err_wrong_auth'];

}
$_SESSION['auth'] = $assoc['password'];
header("Location: $protocol://$server/index.php");
exit;
mysqli_free_result($result);
mysqli_close($dbc);
?>

<?php
	html:
        include("{$_SERVER['DOCUMENT_ROOT']}/html/header.html");
?>
<h1><?=$loginphp['h1_title']; ?></h1>
<h2><?=$loginphp['h2_info']; ?></h2>
<?php
?><html>
<head>
	<title>kawaii - login</title>
	<link rel="stylesheet" type="text/css" href="style.css" />  
</head>
<body>
  <?php if(empty($_POST)): ?>
	   <h3>Logín</h3>
     form action="<?php echo $_SERVER['PHP_SELF']; ?>" method="post">
<fieldset>
<!-- <div align="center"> -->
<legend><b><?=$loginphp['cred_prompt']; ?></b></legend>
<table style="text-align: center; border-width:0; width:100%;">
<tr>
	<td style="width:10%;">&nbsp;</td>
	<td style="width:30%;"><b><?php echo $loginphp['form_input']['email']; ?></b>:</td>
	<td><input id="email" type="text" name="email" size="32" maxlength="127" value="<?php if(isset($_POST['email'])) {echo export_data($_POST['email']);} ?>"></td>
</tr>
<tr>
	<td style="width:10%;">&nbsp;</td>
	<td style="width:30%;"><b><?php echo $loginphp['form_input']['password']; ?>:</b></td> <td><input id="password" type="password" name="password" size="32" maxlength="64"></td>
</tr>
<tr>
	<td style="width:10%;">&nbsp;</td>
	<td style="width:30%;"><input id="login" type="submit" name="login" value="<?php echo $loginphp['form_input']['login']; ?>!"></td>
</tr>
    </form>
  <?php endif;?>
</body>
</html>
