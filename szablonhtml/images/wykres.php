<?php

$podzial[0]=$_GET['czpostojuKBwp'];   //Czas postoju kombajnu
$podzial[1]=$_GET['czpracybezposwp'];   //Czas pracy kombajnu bez posuwu 

function przypisywanie ($podzial)
{
	$podzial=$podzial*3.6+270;
	return $podzial;
}


// create image
$image = imagecreatetruecolor(400, 400);
imagesavealpha($image, true);
 $trans_colour = imagecolorallocatealpha($image, 0, 0, 0, 127);
    imagefill($image, 0, 0, $trans_colour);


$darkblue = imagecolorallocate($image, 0x0F, 0x2F, 0x57);  
$navy     = imagecolorallocate($image, 0x03, 0x40, 0x81);
$gray     = imagecolorallocate($image, 0x6F, 0x82, 0x94);

$podzial[0]= przypisywanie($podzial[0]);
$podzial[1]= przypisywanie($podzial[1]) + $podzial[0] - 270;

imagefilledarc($image, 200, 200, 300, 300, 270, $podzial[0] , $gray, IMG_ARC_PIE);
imagefilledarc($image, 200, 200, 300, 300, $podzial[0], $podzial[1], $darkblue, IMG_ARC_PIE);
imagefilledarc($image, 200, 200, 300, 300, $podzial[1], 630, $navy, IMG_ARC_PIE);

echo 
header("Content-type: image/png");
imagepng($image);

// free memory
imagedestroy($image);

?>