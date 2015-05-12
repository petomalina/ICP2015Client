#!/usr/bin/env bash

txtred='\e[0;31m' # Red
txtgrn='\e[0;32m' # Green
txtblu='\e[0;34m' # Blue
txtrst='\e[0m'    # Text Reset

HEADER="/**
 * @brief ICP projekt 2015 (Maze game)
 * @authors xmalin26, xmasek15
 */"

SRC_DIR="./src"

FILES_LIST=$(find $SRC_DIR -name '*.cpp' -o -name '*.h')
WITHOUT_DOX_LIST=()


for file in ${FILES_LIST[@]}
do
	if ! [[ $(grep -E '@author[s].*' $file) =~ @author[s].* ]]; then
		echo -e "${txtred}File without header:	${txtrst}$file"
		WITHOUT_DOX_LIST+=(${file})
	fi
done


if [ ${#WITHOUT_DOX_LIST[@]} -eq 0 ]; then
	echo -e "${txtgrn}All files have headers.${txtrst}"
else
	echo -e "${txtblu}File/s without headers were detected.${txtrst}"
	read -p "Do you wish to repair it?    " yn
	case $yn in
	    [YyAaTt]* ) echo;;
	    * )	exit;;
	esac

	echo -e "${txtblu}Creating backup${txtrst} to ../backup_before_headers"
	actual_dir=$(pwd)
	rm -rf ../backup_before_headers 2>/dev/null
	mkdir ../backup_before_headers
	cp -r $actual_dir/* ../backup_before_headers

	echo
	echo "Header to insert is:"
	echo "${HEADER}"
	echo

	for file in ${WITHOUT_DOX_LIST[@]}
	do
		echo -e "${txtblu}Repairing:${txtrst} $file"

			tail -n+4 "$file" > temp.file # get rid of first 4 lines 
			echo "${HEADER}" > "$file"
			cat temp.file >> "$file"
	done

	rm temp.file
fi

