#!/bin/sh

case $1 in
  "poweroff") doas poweroff ;;
  "sleep") doas zzz ;;
  "reboot") doas reboot ;;
  "lock") betterlockscreen --lock ;;
esac

powermenulock() {
    LOCK_POWERMENU="$HOME/.cache/eww-powermenu.lock"

run() {
    eww open powermenu -c ~/.config/eww/
}

# Open widgets
if [ ! -f "$LOCK_POWERMENU" ]; then
    eww close powermenu -c ~/.config/eww/
    touch "$LOCK_POWERMENU"
    run
elif [ -f "$LOCK_POWERMENU" ]; then
    eww close powermenu -c ~/.config/eww/
    rm "$LOCK_POWERMENU"
fi
}
powermenulock >/dev/null 2>&1

eww update uptime_poll `uptime -p | sed -e 's/up //g'`
