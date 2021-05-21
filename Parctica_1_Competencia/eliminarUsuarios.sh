#!/bin/bash
ROOT_UID=0
SUCCESS=0

if [ "$UID" -ne "$ROOT_UID" ]
then
  echo "Se debe estar como root para ejecutar este script"
  exit $E_NOTROOT
fi  

file=$1
if [ "${file}X" = "X" ];
then
   echo "Debe indicar el archivo con el listado de usuarios a eliminar..."
   exit 1
fi

archivo=agregar_usuarios.csv
	
while read line ;
do
	username=$(echo $line | cut -d":" -f1)
		
	userdel "${username}"
		
	if [ $? -eq $SUCCESS ];
	then
		echo "-----------------------------------------------------"
		echo "El usuario [${username}] ha sido elimnado correctamente"
		echo "-----------------------------------------------------"
	else
		echo "[ERROR] El usuario [${username}] no se pudo eliminar..."
		echo "-----------------------------------------------------"
	fi
done < ${archivo}
