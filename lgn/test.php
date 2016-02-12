<?php
define('__MODEL_NAME__', 'test');
require_once 'boot.php';

$ajax = new Common_Ajax();

$ajax->setResult('data', array('key' => 'love'));
$ajax->setResult('status', 0);