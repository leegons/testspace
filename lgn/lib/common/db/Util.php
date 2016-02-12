<?php
class Common_Db_Util
{
	/**
	 * make array to string by sql style
	 * 
	 *    if item is numeric, then keep oritext
	 *    
	 *    if item is string, then escape it by sql
	 *       
	 *    if item is array ex: 'key'=>array('t'=>'>', 'v'=>2)
	 *    	 then make t to contact between [v] and key
	 *    	   so item in ex will be: key>2
	 *    
	 * @param string $splice the chars between items
	 * @param array $arr items 
	 * @return string
	 */
	static public function splice($splice, $arr) {
		$len = strlen($splice);
		if (!$splice || !$arr || count($arr) <= 0) {
			return false;
		}
		$str = '';
		foreach ($arr as $k => $v) {
			if (is_numeric($k)) {
				if (is_array($v)) { //not support  numberic->array
					continue;
				}
				$k = '';
			} else {
				if (is_array($v)) {
					$k .= $v['t'];
					$v = $v['v'];
				} else {
					$k .= '=';
				}
			}
			if (!is_numeric($v)) {
				$v = sprintf("'%s'", mysql_real_escape_string($v));
			}
			$str .= sprintf(" %s%s %s", $k, $v, $splice);
		}
		return substr($str, 0, -$len);
	}
}
