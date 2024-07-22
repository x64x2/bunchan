<html>
<head>
	<title>kawaii - new page</title>
	<link rel="stylesheet" type="text/css" href="style.css" />  
</head>
<body>
  <h3>New post </h3>
    <form method="post" action="./index.php?a=newpost">
      <input type="text" name="user_title" placeholder="Title" />
    <br>
      <textarea id="cnt" name="user_content">default text</textarea><br>
  <button type="submit">Send</button>
</form>
</body>
</html>
