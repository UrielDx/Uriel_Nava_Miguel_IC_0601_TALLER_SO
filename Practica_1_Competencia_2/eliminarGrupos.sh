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
   echo "Debe indicar el archivo del listado con nombres de grupos a eliminar..."
   exit 1
fi

eliminarGrupo(){
	eval group="$1"

	groupdel "${group}"
	
	if [ $? -eq $SUCCESS ];
	then
		echo "-----------------------------------------------------"
		echo "Grupo [${group}] ha sido eliminado correctamente"
		echo "-----------------------------------------------------"
	else
		echo "[ERROR] El grupo [${group}] no se pudo eliminar..."
		echo "-----------------------------------------------------"
	fi
}

while IFS=: read -r f1
do
	eliminarGrupo "\${f1}"	
done < ${file}

exit 0
