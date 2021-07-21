#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Libreria.h"
static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this = NULL;

    this = (LinkedList*) malloc(sizeof(LinkedList));

    if(this != NULL)
    {
    	this->size = 0;
    	this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
    	returnAux = this->size;

    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{

	int len;
	len = ll_len(this);

	if(this!=NULL && nodeIndex >= 0 && nodeIndex < len)
	{
		Node* pAuxNode;
		int contador;

		pAuxNode = this->pFirstNode;
		contador = 0;

		while(pAuxNode!=NULL)
		{
			if(contador == nodeIndex)
			{
				return pAuxNode;
				break;
			}
			else
			{
				contador++;
				pAuxNode = pAuxNode->pNextNode;
			}

		}

	}

	return NULL;

}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    int len;
    Node* pPreviousNode;
    Node* pAuxNextNode;
    Node* pNewAuxNode;

    len = ll_len(this);

    if(this!=NULL && nodeIndex >= 0 && nodeIndex <= len)
    {
    	pPreviousNode = getNode (this, nodeIndex-1);
		pAuxNextNode = getNode(this, nodeIndex);

		pNewAuxNode = (Node*)malloc(sizeof(Node));
		pNewAuxNode->pElement = pElement;
		pNewAuxNode->pNextNode = pAuxNextNode;

        if (pPreviousNode == NULL)
        {
            this->pFirstNode = pNewAuxNode;
        }
        else
        {
        	pPreviousNode->pNextNode = pNewAuxNode;
        }

    	this->size++;
    	returnAux = 0;

    }
	return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len;

    len = ll_len(this);

    if(this!= NULL)
    {
        addNode(this,len,pElement);
        returnAux = 0;
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
	void* returnAux = NULL;
	int len;
	Node* pAuxNode;

	len = ll_len(this);

	if(this!=NULL && index >= 0 && index < len)
	{
		pAuxNode = getNode(this, index);
		returnAux = pAuxNode->pElement;

	}
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    int len;
    Node* pAuxNode;

    len = ll_len(this);

    if(this!=NULL && index >= 0 && index < len)
    {
    	pAuxNode = getNode(this, index);

    	pAuxNode->pElement = pElement;

    	returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
	int returnAux = -1;

    Node* pAuxNextNode;
    Node* pAuxPreviousNode;
    Node* pAuxNode;
    int len;

    len = ll_len(this);

    if (this != NULL && index >=0 && index < len)
    {

        pAuxNextNode = getNode(this,index+1);
        pAuxPreviousNode = getNode(this, index-1);
        pAuxNode = getNode(this, index);

        if (pAuxPreviousNode == NULL)
        {

            this->pFirstNode = pAuxNextNode;
        }
        else
        {
        	pAuxPreviousNode->pNextNode = pAuxNextNode;
        }

        free(pAuxNode);

        this->size--;

        returnAux = 0;
     }


  	  return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int i;
	int len;

	len = ll_len(this);

    if (this!=NULL)
    {
        for(i=0;i<len;i++)
        {
            ll_remove(this,0);
        }

        returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
	int returnAux = -1;

	if (this!=NULL)
	{

		ll_clear(this);
		free(this);

	   returnAux = 0;
	}
	    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len;
    int i;
    void* pElementNode;

    len = ll_len(this);

    if(this!=NULL)
    {
    	for(i=0;i<len;i++)
    	{
    		pElementNode = ll_get(this,i);
    		if(pElementNode == pElement)
    		{
    			returnAux = i;
    			break;
    		}
    	}

    }


    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    int len;

    len = ll_len(this);

    if (this != NULL && len != 0)
    {
        returnAux = 0;
    }
    else
    {
    	if(this != NULL && len == 0)
    	{
    		returnAux = 1;
    	}

    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    int len;

    len = ll_len(this);

    if(this!=NULL && index >= 0 && index <= len)
    {

    	returnAux = addNode(this,index,pElement);

    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    void* pAuxElement;

    int len;

    len = ll_len(this);

    if (this != NULL && index >= 0 && index <= len)
    {
    	pAuxElement = ll_get(this,index);
        ll_remove(this,index);
        returnAux = pAuxElement;
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int index;

    if(this!=NULL)
    {
    	returnAux = 1;
    	index = ll_indexOf(this, pElement);

    	if(index == -1)
    	{
    		returnAux = 0;
    	}

    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int i;
    void* pAuxNode;
    int lenTwo;

    lenTwo = ll_len(this2);

    if (this != NULL && this2 != NULL)
    {
    	returnAux = 1;

        for(i=0;i<lenTwo;i++)
        {
        	pAuxNode = ll_get(this2,i);

            if(ll_contains(this,pAuxNode)==0)
            {
                returnAux = 0;
                break;
            }

        }

    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* subList;

    int i;
    void* pAuxElement;
    int len;

    len = ll_len(this);

    if (this != NULL && from >= 0 && from <=len && to > from && to <= len)
    {
    	subList = ll_newLinkedList();

        for(i=from;i<to;i++)
        {
        	pAuxElement = ll_get(this,i);
            ll_add(subList,pAuxElement);
        }
    }

    return subList;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
	LinkedList* cloneList;
	int len;

	len = ll_len(this);

	cloneList = ll_subList(this, 0, len);

    return cloneList;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux = -1;
    void* pElementOne;
    void* pElementTwo;
    void* pAuxElement;
    int len;
    int i;
    int j;

    if(this != NULL && pFunc != NULL && (order==0||order==1))
    {
        returnAux = 0;
        len = ll_len(this);

        for(i=0;i<len-1;i++)
        {
            for(j=i+1;j<len;j++)
            {
            	pElementOne = (void*)ll_get(this,i);
            	pElementTwo = (void*)ll_get(this,j);

                if(order == 0)
                {
                    if(pFunc((void*)pElementOne,(void*)pElementTwo)<0)
                    {
                    	pAuxElement = pElementOne;
                        ll_set(this,i,pElementTwo);
                        ll_set(this,j,pAuxElement);
                    }
                }
                else
                {
                    if(pFunc((void*)pElementOne,(void*)pElementTwo)>0)
                    {
                    	pAuxElement = pElementOne;
                        ll_set(this,i,pElementTwo);
                        ll_set(this,j,pAuxElement);
                    }
                }
            }
        }
    }
    return returnAux;

}


/** \brief Acumula o cuenta algun campo de los elementos de la lista utilizando el retorno la funcion criterio recibida como parametro
 * \param listaLibreria LinkedList*
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return contador int
 *
 */
int ll_count(LinkedList* listaLibreria, int (*fn)(void*))
{
	int len;
	int i;
	int contador;
	void* pAuxElement;

	if(listaLibreria!=NULL && fn!=NULL)
	{
		len = ll_len(listaLibreria);
		contador = 0;

		for(i=0;i<len;i++)
		{
			pAuxElement = (void*)ll_get(listaLibreria, i);

			contador += fn((void*)pAuxElement);
		}

	}

	return contador;
}

/** \brief Agrega un elemento a una nueva lista utilizando el retorno la funcion criterio recibida como parametro a la cual le pasamos la lista de libreria
 * \param listaLibreria LinkedList*
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return contador LinkedList*
 *
 */
LinkedList* ll_filter(LinkedList* listaLibreria, int(*fn)(void*))
{
	LinkedList* listaFiltrada = ll_newLinkedList();
	void* pAuxElement;

	if(listaLibreria != NULL && fn!=NULL)
	{
		int len;
		int i;
		len = ll_len(listaLibreria);

		for(i=0;i<len;i++)
		{
			pAuxElement = (void*)ll_get(listaLibreria, i);
			if(fn((void*)pAuxElement) == 1)
			{
				ll_add(listaFiltrada, pAuxElement);
			}
		}

	}

	return listaFiltrada;
}
