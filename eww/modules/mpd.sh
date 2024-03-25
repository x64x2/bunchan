#!/bin/sh

## Get data
STATUS="$(mpc status)"
COVER="/tmp/.music_cover.jpg"
MUSIC_DIR="$HOME/Music"

playerlock() {
    LOCK_PLAYER="$HOME/.cache/eww-player.lock"

run() {
    eww open player -c ~/.config/eww/
}

# Open widgets
if [ ! -f "$LOCK_PLAYER" ]; then
    eww close player -c ~/.config/eww/
    touch "$LOCK_PLAYER"
    run
elif [ -f "$LOCK_PLAYER" ]; then
    eww close player -c ~/.config/eww/
    rm "$LOCK_PLAYER"
fi
}

## Get status
get_status() {
	if [[ $STATUS == *"[playing]"* ]]; then
		echo ""
	else
		echo "喇"
	fi
}

## Get song
get_song() {
	song=`mpc -f %title% current`
	if [[ -z "$song" ]]; then
		echo "Offline"
	else
		echo "$song"
	fi	
}

## Get artist
get_artist() {
	artist=`mpc -f %artist% current`
	if [[ -z "$artist" ]]; then
		echo "Offline"
	else
		echo "$artist"
	fi	
}

## Get time progress
get_ptime() {
	time=`mpc status %percenttime% | tr -d '[:blank:](%)'`
	if [[ -z "$time" ]]; then
		echo "0"
	else
		echo "$time"
	fi	
}
get_ctime() {
	ctime=`mpc status %currenttime%`
	if [[ -z "$ctime" ]]; then
		echo "0:00"
	else
		echo "$ctime"
	fi	
}
get_ttime() {
	ttime=`mpc status %totaltime%`
	if [[ -z "$ttime" ]]; then
		echo "0:00"
	else
		echo "$ttime"
	fi	
}

get_pretty_ptime() {
  ctime=`mpc status %currenttime%`
	ttime=`mpc status %totaltime%`
	ptime=`mpc status %percenttime% | tr -d '[:blank:]'`

  [ -z "$ttime" ] && return

  echo "$ctime/$ttime ($ptime)"
}

## Get cover
get_cover() {
	ffmpeg -i "${MUSIC_DIR}/$(mpc current -f %file%)" "${COVER}" -y &> /dev/null
	STATUS=$?

	# Check if the file has a embbeded album art
	if [ "$STATUS" -eq 0 ];then
		echo "$COVER"
	else
		echo "images/music.png"
	fi
}

case $1 in 
  "song") get_song ;;
  "artist") get_artist ;;
  "status") get_status ;;
  "time") get_time ;;
  "cover") get_cover ;;
  "current") get_ctime ;;
  "progress") get_ptime ;;
  "ppprogress") get_pretty_ptime ;;
  "toggle")  mpc toggle ;;
  "stop") mpc stop ;;
  "prev") mpc prev && sh ./song.sh cover ;;
  "next") mpc next && sh ./song.sh cover ;;
  "launch") playerlock >/dev/null 2>&1
esac

eww update music_poll="$(mpc current --format '%artist% - %title%')"
eww update music_state_poll="$(mpc status %state%)"
