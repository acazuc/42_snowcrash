<?php
$str = file_get_contents($argv[1]);
$i = 0;
while ($i < strlen($str))
{
		echo chr(ord($str[$i]) - $i);
		$i++;
}
?>
