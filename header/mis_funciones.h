#ifndef MIS_FUNCIONES_H_INCLUDED
#define MIS_FUNCIONES_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

// LOTE 1 - MARCAS

int pedirCodigoMarca()
{
    int codigo;
    bool codigo_valido = false;

    while (!codigo_valido)
    {
        cout << "Ingrese el codigo de la marca (1 a 10): ";
        cin >> codigo;
        if (codigo > 0 && codigo < 11)
        {
            codigo_valido = true;
        }
        else
            cout << "Error: El codigo debe ser un entero entre 1 y 10." << endl;
    }
    return codigo;
}

string pedirNombreMarca()
{
    string nombre_marca;

    cin.ignore();
    do {
        cout << "Ingrese el nombre de la marca: ";
        getline(cin, nombre_marca);
        if (nombre_marca.empty() || nombre_marca == " ")
        {
            cout << endl <<"Error: El nombre no puede estar vacio." << endl << endl;
        }
    } while (nombre_marca.empty() || nombre_marca == " ");

    return nombre_marca;
}

int CargarMarcas(int codigos[], string nombres[], int marcas_requeridas)
{
    int cantidadMarcas = 0;
    for (int i = 0; i < marcas_requeridas; i++)
    {
        codigos[i] = pedirCodigoMarca();
        nombres[i] = pedirNombreMarca();
        cantidadMarcas++;
    }
    return cantidadMarcas;
}

// Lista de marcas
void ListarMarcas(int codigos[], string nombres[], int cantidadMarcas)
{
    cout << endl << "- Lista de Marcas -" << endl;
    for (int i = 0; i < cantidadMarcas; i++) {
        cout << "Codigo: " << codigos[i] << " - Nombre: " << nombres[i] << endl;
    }
}

// Validacion para el menu
bool ValidarMarcasCargadas(int cantidadMarcas, int marcas_requeridas)
{
    return cantidadMarcas == marcas_requeridas;
}


// -------------------------------------------------------------------------------------------------//
// -------------------------------------------------------------------------------------------------//
// LOTE 2 - PRODUCTOS

void CargarProductos(int codigoProductos[], string nombreProducto[], float precioVenta[], float precioCompra[],
                        int stockDisponible[], int codigoMarca[], int codigos[], int cantidadMarcas)
{
    int cantidadProducto = 0, indice = 1;

    while (cantidadProducto < 3)
    {
        cout << "Producto nro. " << indice << endl;

        // Codigo de producto
        int producto;
        do {
            cout << "Ingrese el codigo de producto (3 digitos): ";
            cin >> producto;
            if (producto < 100 || producto > 999)
                cout << endl << "Codigo invalido. Debe tener 3 digitos." << endl <<endl;
        } while (producto < 100 || producto > 999);

        // Nombre del producto
        cin.ignore();
        string nombre;
        do {
            cout << "Ingrese el nombre del producto: ";
            getline(cin, nombre);
            if (nombre.empty())
                cout << endl << "El nombre no puede estar vacio." << endl << endl;
        } while (nombre.empty());

        // Precio de venta
        float pVenta;
        do {
            cout << "Ingrese el precio de venta (mayor a 0): ";
            cin >> pVenta;
            if (pVenta <= 0)
                cout << endl << "Debe ser mayor a 0." << endl << endl;
        } while (pVenta <= 0);

        // Precio de compra
        float pCompra;
        do {
            cout << "Ingrese el precio de compra (mayor a 0): ";
            cin >> pCompra;
            if (pCompra <= 0)
                cout << endl << "Debe ser mayor a 0." << endl << endl;
        } while (pCompra <= 0);

        // Stock disponible
        int stock;
        do {
            cout << "Ingrese el stock disponible (mayor a 0): ";
            cin >> stock;
            if (stock <= 0)
                cout << endl << "Debe ser mayor a 0." << endl << endl;
        } while (stock <= 0);

        // Codigo de marca
        int marca;
        bool marcaValida;
        do {
            cout << "Ingrese el codigo de marca (1 al 10): ";
            cin >> marca;

            marcaValida = false;
            if (marca >= 1 && marca <= 10)
            {
                for (int i = 0; i < cantidadMarcas; i++)
                {
                    if (codigos[i] == marca)
                    {
                        marcaValida = true;
                        break;
                    }
                }
            }

            if (!marcaValida)
                cout << endl << "Codigo de marca invalido o no existe." << endl << endl;

        } while (!marcaValida);

        codigoProductos[cantidadProducto] = producto;
        nombreProducto[cantidadProducto] = nombre;
        precioVenta[cantidadProducto] = pVenta;
        precioCompra[cantidadProducto] = pCompra;
        stockDisponible[cantidadProducto] = stock;
        codigoMarca[cantidadProducto] = marca;

        cantidadProducto++;
        indice++;
        cout << endl;
    }
}

// Lista de productos
void ListarProductos(int codigoProductos[], string nombreProducto[], float precioVenta[],
                      float precioCompra[], int stockDisponible[], int codigoMarca[], int cantidadProducto)
{
    cout << endl <<"- Lista de Productos -" << endl;
    for (int i = 0; i < cantidadProducto; i++)
    {
        cout << "Codigo: " << codigoProductos[i] << " - Nombre: " << nombreProducto[i] << " - Precio Venta: $" << precioVenta[i]
             << " - Precio Compra: $" << precioCompra[i] << " - Stock: " << stockDisponible[i] << " - Marca: " << codigoMarca[i]
             << endl;
    }
}

// Validacion para el menu
bool ValidarProductosCargados(string nombreProducto[])
{
    return !nombreProducto[0].empty();
}


// -------------------------------------------------------------------------------------------------//
// -------------------------------------------------------------------------------------------------//
// LOTE 3 - FORMAS DE PAGO

const int cant_FormasDePago = 5;

bool BuscarCodigo(string codigo, string codigos_validos[], int& posicion)
{
    for (int i = 0; i < cant_FormasDePago; i++)
    {
        if (codigo == codigos_validos[i])
        {
            posicion = i;
            return true;
        }
    }
    return false;
}

bool BuscarRepetido(string codigo, string codigos_cargados[], int cantidadCargada)
{
    for (int i = 0; i < cantidadCargada; i++)
    {
        if (codigo == codigos_cargados[i])
            return true;
    }
    return false;
}

void CargarFormasDePago(string codigo_FormaDePago[], string nombre_FormaDePago[], int porcentaje_FormaDePago[])
{
    string codigos_validos[cant_FormasDePago] = {"EF", "MP", "TR", "TC", "CT"};
    string nombres_validos[cant_FormasDePago] = {"Efectivo", "Mercado Pago", "Transferencia", "Tarjeta de Credito", "Criptomoneda"};

    cout << "# Formas de pago disponibles:" << endl << endl;
    for (int i = 0; i < cant_FormasDePago; i++)
    {
        cout << "- " << nombres_validos[i] << " (" << codigos_validos[i] << ")" << endl;
    }

    for (int i = 0; i < cant_FormasDePago; i++)
    {
        string codigo;
        bool valido = false;

        while (!valido)
        {
            cout << endl << "Ingrese el codigo de forma de pago (en mayuscula): ";
            cin >> codigo;

            int posicion = -1;
            bool encontrado = BuscarCodigo(codigo, codigos_validos, posicion);
            bool repetido = BuscarRepetido(codigo, codigo_FormaDePago, i);

            if (!encontrado)
                cout << endl <<"Codigo invalido. Intente nuevamente." << endl;
            else if (repetido)
                cout << endl <<"Codigo repetido. Intente con otro." << endl;
            else
            {
                codigo_FormaDePago[i] = codigo;
                nombre_FormaDePago[i] = nombres_validos[posicion];
                valido = true;
            }
        }

        cout << "Ingrese porcentaje (negativo = descuento, positivo = interes): ";
        cin >> porcentaje_FormaDePago[i];
    }
}

void ListarFormasDePago(string codigo_FormaDePago[], string nombre_FormaDePago[], int porcentaje_FormaDePago[], int cant_FormasDePago)
{
    cout << endl <<"- Lista de Formas de Pago -" << endl;
    for (int i = 0; i < cant_FormasDePago; i++)
    {
        cout << nombre_FormaDePago[i] << " (" << codigo_FormaDePago[i] << ") - Porcentaje: " << porcentaje_FormaDePago[i] << "%"
             << endl;
    }
}

// Validacion para el menu
bool ValidarFormasPagoCargadas(string nombre_FormaDePago[])
{
    return !nombre_FormaDePago[0].empty();
}


// -------------------------------------------------------------------------------------------------//
// -------------------------------------------------------------------------------------------------//
// LOTE 4 - VENTAS

void CargarVentas(
    int codigoProductos[], string nombreProducto[],
    float precioVenta[], int stockDisponible[],
    int codigoMarcaProducto[],
    string codigoFormaPago[], string nombreFormaPago[],
    int codigosMarca[], string nombresMarca[],
    int cantidadProductos, int cantidadFormasPago, int cantidadMarcas,

    // Acumuladores para reportes
    int cantidadVendidaPorProducto[], float recaudacionPorProducto[], int ventasPorFormaPago[],
    int ventasEf[], int ventasMp[], int ventasTr[], int ventasTc[], int ventasCt[],
    int comprasPorCliente[])
{
    int nro_compra;
    cout << "Ingresar nro de compra (0 para finalizar): ";
    cin >> nro_compra;

    while (nro_compra != 0)
    {
        int codigo_producto;
        string forma_pago;
        int cantidad_vendida;
        int codigo_cliente;
        int dia_venta;

        // Validar código de producto
        int posicion_producto = -1;
        do {
            cout << "Ingresar codigo de producto (3 digitos): ";
            cin >> codigo_producto;

            for (int i = 0; i < cantidadProductos; i++)
            {
                if (codigoProductos[i] == codigo_producto)
                {
                    posicion_producto = i;
                    break;
                }
            }
            if (posicion_producto == -1)
                cout << endl << "Codigo de producto invalido. Intente nuevamente." << endl << endl;
        } while (posicion_producto == -1);

        // Validar forma de pago
        int posicion_fdp = -1;
        do {
            cout << "Ingresar forma de pago (EF, MP, TR, TC, CT): ";
            cin >> forma_pago;

            for (int i = 0; i < cantidadFormasPago; i++)
            {
                if (codigoFormaPago[i] == forma_pago)
                {
                    posicion_fdp = i;
                    break;
                }
            }
            if (posicion_fdp == -1)
                cout << endl <<"Forma de pago invalida. Intente nuevamente." << endl << endl;
        } while (posicion_fdp == -1);

        // Validar cantidad vendida
        do {
            cout << "Ingresar cantidad vendida (> 0): ";
            cin >> cantidad_vendida;

            if (cantidad_vendida <= 0)
                cout << endl <<"Cantidad invalida. Debe ser mayor a 0." << endl << endl;
        } while (cantidad_vendida <= 0);

        // Validar cliente
        do {
            cout << "Ingresar codigo de cliente (1 a 50): ";
            cin >> codigo_cliente;

            if (codigo_cliente < 1 || codigo_cliente > 50)
                cout << endl <<"Codigo de cliente invalido. Debe ser entre 1 y 50." << endl << endl;
        } while (codigo_cliente < 1 || codigo_cliente > 50);

        // Validar día de venta
        do {
            cout << "Ingresar dia de la venta (1 a 30): ";
            cin >> dia_venta;

            if (dia_venta < 1 || dia_venta > 30)
                cout << endl <<"Dia invalido. Debe ser entre 1 y 30." << endl << endl;
        } while (dia_venta < 1 || dia_venta > 30);


        // PROCESAMIENTOS

        // Reporte 1 - Recaudacion y cantidad vendida por producto
        cantidadVendidaPorProducto[posicion_producto] += cantidad_vendida;
        recaudacionPorProducto[posicion_producto] += cantidad_vendida * precioVenta[posicion_producto];

        // Reporte 2 - Porcentaje de ventas por forma de pago
        ventasPorFormaPago[posicion_fdp]++;

        // Reporte 3 - Ventas por marca y forma de pago
        int marcaProducto = codigoMarcaProducto[posicion_producto];
        int indiceMarca = -1;

        for (int i = 0; i < cantidadMarcas; i++)
        {
            if (codigosMarca[i] == marcaProducto)
            {
                indiceMarca = i;
                break;
            }
        }

        if (indiceMarca != -1)
        {
            if (codigoFormaPago[posicion_fdp] == "EF")
                ventasEf[indiceMarca] += cantidad_vendida;
            else if (codigoFormaPago[posicion_fdp] == "MP")
                ventasMp[indiceMarca] += cantidad_vendida;
            else if (codigoFormaPago[posicion_fdp] == "TR")
                ventasTr[indiceMarca] += cantidad_vendida;
            else if (codigoFormaPago[posicion_fdp] == "TC")
                ventasTc[indiceMarca] += cantidad_vendida;
            else if (codigoFormaPago[posicion_fdp] == "CT")
                ventasCt[indiceMarca] += cantidad_vendida;
        }


        // Reporte 5 - top 10 clientes con mas ventas
        comprasPorCliente[codigo_cliente]++;

        stockDisponible[posicion_producto] -= cantidad_vendida;

        cout << endl << "Venta registrada correctamente." << endl;
        cout << endl << "Ingresar nro de compra (0 para finalizar): ";
        cin >> nro_compra;
    }
}

// Validacion para el menu
bool HayVentasCargadas(int cantidadVendidaPorProducto[], int cantProductos)
{
    for (int i = 0; i < cantProductos; i++)
    {
        if (cantidadVendidaPorProducto[i] > 0)
            return true;
    }
    return false;
}


// -------------------------------------------------------------------------------------------------//
// -------------------------------------------------------------------------------------------------//
// 5 - REPORTES

// Reportes 1 - Recaudacion por producto
void Reporte_RecaudacionPorProducto(int codigoProductos[], string nombreProducto[], float recaudacionPorProducto[],
                                    int cantidadVendidaPorProducto[], int stockDisponible[], int cantidadProductos)
{
    int indices[cantidadProductos];
    for (int i = 0; i < cantidadProductos; i++)
        indices[i] = i;

    for (int i = 0; i < cantidadProductos - 1; i++)
    {
        for (int j = 0; j < cantidadProductos - i - 1; j++)
        {
            if (cantidadVendidaPorProducto[indices[j]] < cantidadVendidaPorProducto[indices[j + 1]]) {
                int temp = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = temp;
            }
        }
    }

    cout << endl << "- Recaudacion por producto -" << endl;
    for (int k = 0; k < cantidadProductos; k++)
    {
        int idx = indices[k];
        if (cantidadVendidaPorProducto[idx] > 0)
        {
            cout << "Codigo del producto: " << codigoProductos[idx] << " - Nombre: " << nombreProducto[idx] << " - Vendidos: " << cantidadVendidaPorProducto[idx]
                 << " - Recaudado: $" << recaudacionPorProducto[idx] << " - Stock restante: " << stockDisponible[idx] << endl;
        }
    }
    cout << endl;
}

// Reporte 2 - Porcentaje por forma de pago
void Reporte_PorcentajePorFormaDePago(string nombreFormaPago[], int ventasPorFormaPago[])
{
    int totalVentas = 0;
    for (int i = 0; i < 5; i++) {
        totalVentas += ventasPorFormaPago[i];
    }

    cout << endl << "- Porcentaje de ventas por forma de pago -" << endl;

    if (totalVentas == 0)
    {
        cout << "No se registraron ventas." << endl;
        return;
    }

    for (int i = 0; i < 5; i++)
    {
        float porcentaje = (float)ventasPorFormaPago[i] * 100 / totalVentas;
        cout << nombreFormaPago[i] << ": " << porcentaje << "%" << endl;
    }
    cout << endl;
}

// Reporte 3 - Ventas por marca y forma de pago
void Reporte_VentasPorMarcaYFormaPago(string nombresMarca[], int cantidadMarcas, int ventasEf[],
                                       int ventasMp[], int ventasTr[], int ventasTc[], int ventasCt[])
{
    cout << endl << "- Ventas por Marca y Forma de Pago -" << endl << endl;

    for (int i = 0; i < cantidadMarcas; i++)
    {
        cout << "Marca: " << nombresMarca[i] << endl;
        cout << "  - Efectivo: " << ventasEf[i] << " unidades" << endl;
        cout << "  - Mercado Pago: " << ventasMp[i] << " unidades" << endl;
        cout << "  - Transferencia: " << ventasTr[i] << " unidades" << endl;
        cout << "  - Tarjeta de Credito: " << ventasTc[i] << " unidades" << endl;
        cout << "  - Criptomoneda: " << ventasCt[i] << " unidades" << endl;
        cout << "----------------------------------------" << endl;
    }

    cout << endl;
}

// Reporte 4 - Productos sin ventas
void Reporte_ProductosSinVentas(int codigoProductos[], string nombreProducto[], int cantidadVendidaPorProducto[], int cantidadProductos)
{
    cout << endl << "- Productos sin ventas -" << endl;

    bool haySinVentas = false;
    for (int i = 0; i < cantidadProductos; i++)
    {
        if (cantidadVendidaPorProducto[i] == 0)
        {
            haySinVentas = true;
            cout << "Codigo del producto: " << codigoProductos[i] << " - Nombre: " << nombreProducto[i] << endl;
        }
    }
    cout << endl;

    if (!haySinVentas)
        cout << "Todos los productos registraron ventas." << endl << endl;
}

// 5 - Reporte Top 10 Clientes Y Cupones
#include <cstdlib>
#include <ctime>

void Reporte_Top10ClientesYCupones(int comprasPorCliente[])
{
    // Verctor de índices de clientes
    int indices[51];
    for (int i = 1; i <= 50; i++)
        indices[i] = i;

    // Ordenar índices segun mayor a menor la cantidad de compras
    for (int i = 1; i < 50; i++)
    {
        for (int x = i + 1; x <= 50; x++)
        {
            if (comprasPorCliente[indices[i]] < comprasPorCliente[indices[x]])
            {
                int temp = indices[i];
                indices[i] = indices[x];
                indices[x] = temp;
            }
        }
    }

    // Listado del top 10 de clientes
    cout << endl << "- Top 10 clientes con mas compras -" << endl;
    int top10 = 0;
    for (int i = 1; i <= 50 && top10 < 10; i++)
    {
        if (comprasPorCliente[indices[i]] > 0)
        {
            cout << "Codigo de cliente: " << indices[i] << " - Compras: " << comprasPorCliente[indices[i]] << endl;
            top10++;
        }
    }

    // Sorteo entre el top 10
    cout << endl << "- Sorteo de cupones (3 ganadores) -" << endl;
    srand(time(NULL));
    bool elegido[11] = {};

    int ganadores = 0;
    while (ganadores < 3)
    {
        int pos = (rand() % top10) + 1;
        if (!elegido[pos])
        {
            elegido[pos] = true;
            int clienteGanador = indices[pos];
            cout << "# Ganador - Codigo de cliente: " << clienteGanador << " - Compras: " << comprasPorCliente[clienteGanador] << endl;
            ganadores++;
        }
    }
    cout << endl;
}

#endif
