<?php

$fileName = 'input.csv';

$list = file($fileName);

sort($list, SORT_NUMERIC);

foreach ($list as $value) {
	echo $value;
}

