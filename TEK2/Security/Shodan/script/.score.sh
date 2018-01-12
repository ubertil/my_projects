#!/bin/bash

score()
{
  curl -X POST --cacert cert.pem -H "Content-Type:application/json" -u `cat ../API/.team.txt`:`cat ../API/.caca.txt` --data "{\"chinpokomon\":\"$1\", \"flag\":\"$2\"}" https://shodan.epitech.eu/api/1.2/score
}

score $1 $2
