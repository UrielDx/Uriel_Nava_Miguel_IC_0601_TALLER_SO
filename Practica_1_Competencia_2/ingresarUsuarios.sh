#!/bin/bash
ROOT_UID=0

if [ "$UID" -ne "$ROOT_UID" ]
then
  echo "Se debe estar como root para ejecutar este script"
  exit $E_NOTROOT
fi 

file=$1
if [ "${file}X" = "X" ];
then
   echo "Debe indicar el archivo del listado con nombres de usuarios a eliminar..."
   exit 1
fi

echo "-----------------------------------------------------"
echo "Realizando cat agregar_usuarios.csv ..."
cat agregar_usuarios.csv
echo "-----------------------------------------------------"

archivo=agregar_usuarios.csv
	
while read line ;
do
	username=$(echo $line | cut -d":" -f1)
	PASSWORD=$(echo $line | cut -d":" -f2)
	USID=$(echo "$line" | cut -d":" -f3)
	UGID=$(echo "$line" | cut -d":" -f4) 
	uinfo=$(echo "$line" | cut -d":" -f5)
	directory=$(echo "$line" | cut -d":" -f6)
	cshell=$(echo "$line" | cut -d":" -f7)
	
		if grep -q $username /etc/passwd ;
		then
			echo "-------------------------------------------------------------------"
			echo "[ERROR] El usuario [${username}] ya existe, no se puede agregar..."
			echo "-------------------------------------------------------------------"
		else
			echo "---------------------------------------------------------------------------"
			echo "El usuario [${username}] no existe..."
				if grep -q ${UGID} /etc/group ;
				then
					echo "El grupo [${UGID}] existe..."
					useradd -u ${USID} -g ${UGID} -c ${uinfo} -s ${cshell} -p ${PASSWORD} ${username}
					echo "Ruta Home Directory --> ${directory}"
					echo "Ruta Shell Command --> ${cshell}"
					echo "El usuario [${username}] se ha agregado correctamente"
				else
					echo "[ERROR] El grupo [${UGID}] no existe, [${username}] no se pudo agregar..." 
					echo "---------------------------------------------------------------------------"
				fi
		fi
done < ${archivo}
