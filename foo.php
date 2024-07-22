<?php
//┌─────────── CONSTANTS ────────────┐
  const STYLE_TOKENS=['__','**','//'];
  const LINK_TOKEN=["-[","]-"];
  const BR="<br>";
  const VER="v0.10";

  const THREAD_DB_FILE="/db/thread.db";
  const USER_DB_FILE="/db/user.db";
//└──────────────────────────────────┘

//┌──────────── GLOBAL FUNCTIONS ──────────────────
function printLogo(){
  echo '<h1><span id="logo1">php</span><span id="logo2">bbs</span><sup id="logover">'.VER.'</sup> </h1>';
  echo '<hr>';
  return null;
}

function printError($error) {
		if (!empty($error)) {
				echo '<small class="error">' .$error. '</small><br />';
		}
}



function printMenu(){
  echo '<span class="menu">|<a href="new.php">new post</a>|<a href="/docs/changelog.html">changelog</a></span>';
}

function initdb(){
global $db;
global $dbusr;
if (file_exists(THREAD_DB_FILE) and file_exists(USER_DB_FILE)){
    $tftxt=file_get_contents(THREAD_DB_FILE);
    $uftxt=file_get_contents(USER_DB_FILE);
    $db=unserialize($tftxt);
    $dbusr=unserialize($uftxt);
  }else{
    printError('A .db file is missing or empty');

  }
}

function savedb(){
  global $db;
  global $dbusr;
  file_put_contents(THREAD_DB_FILE,serialize($db));
  file_put_contents(USER_DB_FILE,serialize($dbusr));
}

function newuser($uname,$upwd){
  global $dbusr;
  if(strlen($upwd)<6){
    printError("password must be at least 6 characters");
    return null;
  }elseif(strlen($uname)<3){
    printError("username must be at least 3 characters");
    return null;

  }
  foreach($dbusr as $uar){
    if ($uar['n']==$uname){
      printError("user $uname already exists");
      return null;
    }
  }
  $dbusr[]=["n" => $uname,
            "p" => password_hash($upwd, PASSWORD_DEFAULT),
            'op' => [], 'id'=>sizeof($dbusr),
            'bd'=>date('jS \of F Y h:i:s A'),
            'votes'=>[],
            'g'=>0,];
  echo "<strong>registration sucessful</strong>";
  savedb();
}

function verifylogin($user,$enteredpass){
  global $dbusr;
  foreach ($dbusr as $k=>$u){
    if ($u['n']==$user){
      $storedhash=$u['p'];
      $uindex=$k;
      break;
    }
  }
  if($storedhash==null){
    printError('user not found');
    return null;
  }
  if(password_verify($enteredpass,$storedhash)) {
    setcookie('uindex', $uindex,0);
    setcookie('hash', $storedhash,0); 
    echo '<p class="notify">You are now logged in.</p>';
    return true;
  }else {
    printError('Invalid password.');
    return null;
  }
}

function checkadmin(){
  //  TODO
  global $dbusr;
   
  

}


function checksec($u,$p){
  // check if hash in cookie is same as stored hash
  global $dbusr;
  if($dbusr[$u]['p']==$p){
    return $dbusr[$u]['n'];
  }
  else{
    return false;
  }
}

function newpage($ttl,$txt){
  global $db;
  global $dbusr;
  $pageindex=count($db);
  foreach($db as $p){
    if ($p['t']==$ttl){
      printError("post named $ttl already exists in the main DB.");
      return null;
    }  
  }
  foreach($dbusr as $k=>$u){
    if(checksec($_COOKIE["uindex"],$_COOKIE["hash"]) == $u['n']){ //im ugly fixme pls
      array_push($dbusr[$k]['op'],$pageindex);
    }
  }  
  array_push($db, ['t' => $ttl, 'c' => $txt, "a"=>checksec($_COOKIE["uindex"],$_COOKIE["hash"]),"ts"=>date('jS \of F Y h:i:s A'),"com"=>[],'vo'=>0,'vi'=>0 ]);
  echo '<p class="notify"> Created new post '.$_POST['user_title'].' </p>'; 
  savedb();
}

function editpagetext($ind,$newtxt){
  global $db;
  $db[$ind]['c']=$newtxt;
  // $db[$ind]['hist']=>[$db[$ind]['
  savedb();
}

function showlatestposts(){
  global $db;
  $rev=array_reverse($db,true);
  foreach ($rev as $k=>$p){
    echo '<u class="votes">'.$p['vo'].'</u><a href="/view.php?index='.$k.'">'.$p['t'].'</a>'."<em>[{$p['a']}] </em> <small class=\"tsdiff\">{$ddiff}  </small>"."<b>".count($p['com'])." comments</b><br>";
  }
}

function homepage(){
  global $db;
  global $dbusr;
  echo '<h2>'.'New Posts:'.'</h2>';
  $lastfivepages=array_reverse(array_slice($db,-5,5,true),true);
  foreach($lastfivepages as $k=>$p){
    $pd=date_create_from_format('jS \of F Y h:i:s A',$p['ts']);
    $cd=date_create('now');
    $ddiff=date_diff($cd,$pd)->format('%a days %h h %i m ago');
    echo '<a href="/view.php?index='.$k.'">'.$p['t'].'</a>'.'<u class="votes">['.$p['vo'].']</u>'."<em>[{$p['a']}] </em> <small class=\"tsdiff\">{$ddiff}  </small>"."<b>".count($p['com'])." comments</b><br>";
  }
  // TODO make a link to see all latest posts here
  echo '<h2>'.'New Users:'.'</h2>';
  $lastfiveusers=array_reverse(array_slice($dbusr,-5,5,true),true);
  foreach($lastfiveusers as $k=>$u){
    echo '<a href="/profile.php?uindex='.$k.'">'.$u['n'].'</a><br>';
  }
  
}


function viewpage($ind,$updviews=true){
  # put boilerplate below into corresponding html doc
  global $db;
  if($updviews){
    $db[$ind]['vi']++;
  }
  savedb();
  $p=$db[$ind];
  echo "<h1 class=\"view_title\">{$p['t']}</h1>";
  $pd=date_create_from_format('jS \of F Y h:i:s A',$p['ts']);
  $cd=date_create('now');
  $ddiff=date_diff($cd,$pd)->format('%a days %h h %i m ago');
  echo "<span class=\"view_auth\">written by : ".'<a href="profile.php?uindex='.getindexfromusername($p['a']).'">'.$p['a']."</a></span><br>";
  echo "<span class=\"view_time\">{$p['ts']}</span>";
  echo "<small class=\"tsdiff\">".$ddiff.'</small>';
  
  $lines=explode("\n",$p['c']);
  foreach($lines as $l){
    if($l[0]=="#" and $l[1]==" "){
      echo '<h3>'.$l.'</h3>'.'<br>';  
    }
    echo '<p class="view_cont">'.parseline($l).'</p>';  
  }
  echo '<hr>';
  echo '<u>Post score: '.$p['vo'].'</u>';
  echo '<button name="voted" value="1" form="voteform">UpVote</button>';
  echo '<button name="voted" value="-1" form="voteform">DownVote</button><br>';
  echo '<span class="view_view">Post read '.$p['vi'].' times.</span>';
  echo '<h3>'.count($p['com']).' comments:</h3>';
  echo '<div class="comments_box">';
  foreach($p['com'] as $c){
    echo '<div class="comment">';
    echo '<u class="com_auth">'.$c['a'].'</u>'.'<small class="com_tstamp">'.$c['ts'].'</small>';
    echo '<p class="com">'.$c['c'].'</p>';
    echo '</div>';
     
  }
  echo '</div>';
}

function viewprofile($uindex){
  global $db;
  global $dbusr;
  $cusr=$dbusr[$uindex];
  echo '<h2>User : '.$cusr['n'].'</h2>';
  $pd=date_create_from_format('jS \of F Y h:i:s A',$cusr['bd']);
  $cd=date_create('now');
  $ddiff=date_diff($cd,$pd)->format('%a days %h h %i ago');
  echo '<em class="tsdiff">Registered '.$ddiff.'</em><br>';
  echo '<span class="grat">Gratitude: '.$cusr['g'].'</span> <a href="/docs/help.html#gratitude">?</a>';
  echo '<h2>Original Posts ('.count($cusr['op']).'):</h2>';
  echo '<ul>';
  foreach($cusr['op'] as $k){
    echo '<li>'.'<a href="view.php?index='.$k.'">'.gettitlefromindex($k).'</a>';
  }
  echo '</ul>';
}

function parseline($l){
  // parse single line for markup
  // replacing string with html if markup is found
  // finally return modified line to b displayed
  foreach(STYLE_TOKENS as $st){
      $startpos=strpos($l,$st);
      $endpos=strpos($l,$st,$startpos+2);
      if($startpos and $endpos){
        $midstr=substr($l,$startpos+2,$endpos-($startpos+2));
        $needle=$st.$midstr.$st;
        switch ($st){
        case '__':
          $l=str_replace($needle,"<u>$midstr</u>",$l); 
          break;
        case '**':
          $l=str_replace($needle,"<b>$midstr</b>",$l); 
          break;
        case '//':
          $l=str_replace($needle,"<em>$midstr</em>",$l); 
      }
    }
  }
  $linkstartpos=strpos($l,LINK_TOKEN[0]);
  $linkendpos=strpos($l,LINK_TOKEN[1]);
  if($linkstartpos and $linkendpos){
    $midstr=substr($l,$linkstartpos+2,$linkendpos-($linkstartpos+2));
    $needle=LINK_TOKEN[0].$midstr.LINK_TOKEN[1];
    $l=str_replace($needle,'<a class="link" href="?index='.getindexfromtitle($midstr).'">'."$midstr</a>",$l); 
  }
  return $l;
}

function addcomment($pindex,$comtext){
  global $db;
  // todo : check if pindex exists inside db first !
  $db[$pindex]['com'][]=['a'=>checksec($_COOKIE["uindex"],$_COOKIE["hash"]),'c'=>$comtext,'ts'=>date('jS \of F Y h:i:s A')];
  echo '<p class="notify"> Submitted comment sucessfully. </p>'; 
  savedb();
    
}

function addvote($pindex,$votedelta){
  global $db;
  global $dbusr;
  if(in_array($pindex,$dbusr[$_COOKIE['uindex']]['votes'])){
    printError("You can only vote once");
    return null;
  }else{
    $db[$pindex]['vo']+=$votedelta;
    $dbusr[$_COOKIE['uindex']]['votes'][]=$pindex;
    $dbusr[$_COOKIE['uindex']]['g']+=$votedelta;
  }
  savedb();
}

function getindexfromtitle($ttl){
  global $db;
  foreach ($db as $k=>$p){
    if($p['t'] == $ttl){
      return $k;
    }
  }
  return null;
}

function gettitlefromindex($ind){
  global $db;
  return $db[$ind]['t'];
}

//TODO make getusername from index func

function getindexfromusername($uname){
  global $dbusr;
  foreach ($dbusr as $k=>$u){
    if($u['n'] == $uname){
      return $k;
    }
  }
  return null;
}

function getusername($ind){
  global $dbusr;
  return $dbusr[$ind]['n'];
}

function getcontent_nl2br($ind){
  global $db;
  return $db[$ind]['c'];
}

function getscore($ind){
// Returns post score from _index_
// Also takes care of stylising the score as such : [s] 
  global $db;
  return '['.$db[$ind]['vo'].']';
}



// ├─────────── MAIN ──────────────
initdb();
if (!isset($_POST['luser']) and !isset($_POST['lpassword'])){
printLogo(); 
if($u=checksec($_COOKIE["uindex"],$_COOKIE["hash"])){
    echo '<small class="notify">Logged in as '.$u.'</small><br>';
    echo '<hr>'; 
}
}
?>
