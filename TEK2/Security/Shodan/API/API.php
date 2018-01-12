<?php
ini_set('display_errors', 1);

class Shodan_API
{
	/**
	 * Version name
	 * 
	 * @var string
	 */
	private static $version;

	/**
	 * API Endpoint
	 * 
	 * @var string
	 */ 
	private static $url;

	/**
	 * Our team name
	 * 
	 * @var string
	 */
	private static $our_team;

	public function __construct($version)
	{
		self::$version = $version . '/';
		self::$url = "https://shodan.epitech.eu/api/";
		$team = trim(file_get_contents(".team.txt"));
		self::$our_team = ((isset($team) && !empty($team)) ? ($team) : (""));
	}

	private static function request($url, $ispost = false, $data = null)
	{
		$ch = curl_init();
		$doc = new DOMDocument();
		if ($ispost == true) {
			curl_setopt($ch, CURLOPT_POST, true);
			curl_setopt($ch, CURLOPT_POSTFIELDS, $data);
		}
        curl_setopt($ch, CURLOPT_URL, $url);
        curl_setopt($ch, CURLOPT_HTTPHEADER, array('Content-Type: application/json'));
        curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
        curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, true);
		curl_setopt($ch, CURLOPT_SSL_VERIFYHOST, 2);
		curl_setopt($ch, CURLOPT_FAILONERROR, 1);
		curl_setopt($ch, CURLOPT_SSLCERTTYPE, "PEM");
		curl_setopt($ch, CURLOPT_SSLCERT, getcwd() . '/.cert.pem');
        $output = curl_exec($ch); 
        curl_close($ch);
		$doc->loadHTML($output);
		$script_tags = $doc->getElementsByTagName('script');
		$length = $script_tags->length;
		for ($i = 0; $i < $length; $i++) {
  			$script_tags->item($i)->parentNode->removeChild($script_tags->item($i));
		}
		$sanitized = $doc->saveHTML();
		return ($sanitized);
	}

	public static function team_info($team = null)
	{
		$data = self::request(self::$url . self::$version . 'team-info/' . ((isset($team) && !empty($team)) ? ($team) : (self::$our_team)));
		var_dump($data);
	}

	public static function team_score($team = null)
	{
		$data = self::request(self::$url . self::$version . 'team-score/' . ((isset($team) && !empty($team)) ? ($team) : (self::$our_team)));
		var_dump($data);
	}

	public static function get_topten()
	{
		$data = self::request(self::$url . self::$version . 'topten/');
		var_dump($data);
	}

	public static function list_chinpokomons()
	{
		$data = self::request(self::$url . self::$version . 'chinpokodex/');
		var_dump($data);
	}

	public static function list_challenges()
	{
		$data = self::request(self::$url . self::$version . 'challenges/');
		var_dump($data);
	}

	public static function challenge_info($name)
	{
		$params = array(
			"name" => $name
			);
		$data = self::request(self::$url . self::$version . 'challenge-info/', true, $params);
		var_dump($data);
	}

	public static function score_challenge($chinpokomon, $flag)
	{
		$params = array(
			"flag" => $flag,
			"chinpokomon" => $chinpokomon
			);
		$data = self::request(self::$url . self::$version . 'chinpokodex/', true, $params);
		var_dump($data);
	}
};

function init()
{
	$ennemies = array(
		"TOM" => "dinomobile",
		"YAMMER" => "caramba"
		);
	$version = "1.2";
	$shodan = new Shodan_API($version);
	$shodan->get_topten();
	foreach ($ennemies as $team) {
		$shodan->team_info($team);
	}
}

init();
?>