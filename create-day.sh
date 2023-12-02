if [ $# -eq 1 ]
then 
    if [ -d "$1-Day" ]
    then 
        echo "Folder Already Exists!"
    else 
        mkdir "$1-Day"
        mkdir "$1-Day/1-Part"
        mkdir "$1-Day/2-Part"

        touch "$1-Day/1-Part/main.cpp"
        touch "$1-Day/1-Part/input"
        touch "$1-Day/2-Part/main.cpp"
        touch "$1-Day/2-Part/input"
    fi
else 
    echo "Usage : sh create-day.sh [day-number]"
fi