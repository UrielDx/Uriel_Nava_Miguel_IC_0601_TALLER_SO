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
   echo "Debe indicar el archivo del listado con Nombres de grupo a ingresar..."
   exit 1
fi

echo "-----------------------------------------------------"
echo "Realizando cat agregar_grupos.csv ..."
cat agregar_grupos.csv
echo "-----------------------------------------------------"

crearGrupo(){
	eval nombreGrupo="$1"

	groupadd "${nombreGrupo}"
	
	if [ $? -eq $SUCCESS ];
	then
		echo "-----------------------------------------------------"
		echo "Grupo [${nombreGrupo}] agregado correctamente..."
		echo "-----------------------------------------------------"
	else
		echo "[ERROR] El grupo [${nombreGrupo}] no se pudo agregar..."
		echo "-----------------------------------------------------"
	fi
}

while IFS=: read -r f1
do
	crearGrupo "\${f1}"	
done < ${file}

exit 0
