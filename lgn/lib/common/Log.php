<?php

class Common_Log
{
	// log level
	const LOG_ALL     = 0x1f;
	const LOG_DEBUG   = 0x10;
	const LOG_TRACE   = 0x08;
	const LOG_NOTICE  = 0x04;
	const LOG_WARNING = 0x02;
	const LOG_FATAL   = 0x01;
	
	static $log_level_str = array(
			self::LOG_DEBUG => 'DEBUG',
			self::LOG_TRACE => 'TRACE',
			self::LOG_NOTICE => 'NOTICE',
			self::LOG_WARNING => 'WARNING',
			self::LOG_FATAL => 'FATAL',	
	);
	
	// for notice
	static protected $notice_arr = array();
	
	static protected $config = array(
			'normal_log' => 'log/php.log',
			'alter_log'  => 'log/php.log.wf',
			'log_level'  => self::LOG_ALL,
	);
	
	/**
	 * set config for log
	 * @param string $option include [mormal_log, alter_log, log_level]
	 * @param string $value 
	 */
	static public function set($option, $value) {
		self::$config[$option] = $value;
	}
	
	static public function debug($fmt) {
		$args = func_get_args();
		array_shift($args);
		return self::write_log(self::LOG_DEBUG, $fmt, $args);
	}
	
	static public function trace($fmt) {
		$args = func_get_args();
		array_shift($args);
		return self::write_log(self::LOG_TRACE, $fmt, $args);
	}
	
	static public function addNotice($k, $v = null) {
		if (is_array($k)) {
			self::$notice_arr = array_merge(self::$notice_arr, $k);
		} else if ($v == null) {
			self::$notice_arr[] = $k;
		} else {
			self::$notice_arr[$k] = $v;
		}
	}
	
	static public function notice($fmt) {
		// extend notice content
		$ext_content = '';
		foreach (self::$notice_arr as $k => $v) {
			if (is_numeric($k)) {
				$ext_content .= $v;
			} else {
				$ext_content .= " ${k}[${v}]";
			}
		}
		self::$notice_arr = array();
		
		// add extend notice content in args
		$args = func_get_args();
		array_shift($args);
		array_push($args, $ext_content);
		
		return self::write_log(self::LOG_NOTICE, "%s ". $fmt, $args);
	}

	static public function warning($fmt) {
		$args = func_get_args();
		array_shift($args);
		return self::write_log(self::LOG_WARNING, $fmt, $args);
	}
	
	static public function fatal($fmt) {
		$args = func_get_args();
		array_shift($args);
		return self::write_log(self::LOG_FATAL, $fmt, $args);
	}

	static protected function write_log($level, $fmt, $args) {
		if (!($level & self::$config['log_level'])) {
			return;
		}
		$level_str = self::$log_level_str[$level];
		$ori_str = vsprintf($fmt, $args);
		$time_str = date('Y-m-d H:i:s');
		
		switch ($level) {
			case self::LOG_DEBUG:
			case self::LOG_TRACE:
			case self::LOG_NOTICE:
				$log_file = self::$config["normal_log"];
				break;
			case self::LOG_WARNING:
			case self::LOG_FATAL:
				$log_file = self::$config["alter_log"];
				break;
		}
		
		$log_str = sprintf("[%s] %s %s\n", $level_str, $time_str, $ori_str);
		file_put_contents($log_file, $log_str, FILE_APPEND);
	}
}
