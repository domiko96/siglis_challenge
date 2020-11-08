#ifndef BLE_FIZZ_BUZZ_H__
#define BLE_FIZZ_BUZZ_H__

#include <stdint.h>
#include <stdbool.h>
#include "ble.h"
#include "ble_srv_common.h"

/**@brief   Macro for defining a ble_hrs instance.
 *
 * @param   _name   Name of the instance.
 * @hideinitializer
 */
#define BLE_FIZZ_BUZZ_DEF(_name)              \
static ble_fizz_buzz_t _name;                  \
NRF_SDH_BLE_OBSERVER(_name ## _obs,             \
                     BLE_HRS_BLE_OBSERVER_PRIO,  \
                     ble_fizz_buzz_on_ble_evt, &_name)


// CUSTOM_SERVICE_UUID_BASE
#define FIZZ_BUZZ_UUID_BASE {0x02, 0x00, 0x12, 0xac, 0x42, 0x02, 0xc1, 0xad, 0xeb, 0x11, 0xb8, 0x21, 0x14, 0x8d, 0x5e, 0x0c}

#define FIZZ_BUZZ_SERVICE_UUID               0x1400
#define FIZZ_BUZZ_VALUE_CHAR_UUID            0x1401
																					
/**@brief Custom Service event type. */
typedef enum
{
    BLE_FIZZ_BUZZ_EVT_NOTIFICATION_ENABLED,
    BLE_FIZZ_BUZZ_EVT_NOTIFICATION_DISABLED,
    BLE_FIZZ_BUZZ_EVT_DISCONNECTED,
    BLE_FIZZ_BUZZ_EVT_CONNECTED
} ble_fizz_buzz_evt_type_t;

/**@brief Custom Service event. */
typedef struct
{
    ble_fizz_buzz_evt_type_t evt_type;                                  /**< Type of event. */
} ble_fizz_buzz_evt_t;

// Forward declaration of the ble_fizz_buzz_t type.
typedef struct ble_fizz_buzz_s ble_fizz_buzz_t;


/**@brief Custom Service event handler type. */
typedef void (*ble_fizz_buzz_evt_handler_t) (ble_fizz_buzz_t * p_bas, ble_fizz_buzz_evt_t * p_evt);

typedef struct
{
    ble_fizz_buzz_evt_handler_t         evt_handler;                    /**< Event handler to be called for handling events in the Custom Service. */
    uint8_t                       initial_fizz_buzz_value;           /**< Initial custom value */
    ble_srv_cccd_security_mode_t  custom_value_char_attr_md;     /**< Initial security level for Custom characteristics attribute */
} ble_fizz_buzz_init_t;

/**@brief Custom Service structure. This contains various status information for the service. */
struct ble_fizz_buzz_s
{
    ble_fizz_buzz_evt_handler_t         evt_handler;                    /**< Event handler to be called for handling events in the fizz_buzztom Service. */
    uint16_t                      service_handle;                 /**< Handle of fizz_buzztom Service (as provided by the BLE stack). */
    ble_gatts_char_handles_t      fizz_buzz_value_handles;           /**< Handles related to the Custom Value characteristic. */
    uint16_t                      conn_handle;                    /**< Handle of the current connection (as provided by the BLE stack, is BLE_CONN_HANDLE_INVALID if not in a connection). */
    uint8_t                       uuid_type; 
};

/**@brief Function for initializing the Custom Service.
 *
 * @param[out]  p_cus       Custom Service structure. This structure will have to be supplied by
 *                          the application. It will be initialized by this function, and will later
 *                          be used to identify this particular service instance.
 * @param[in]   p_cus_init  Information needed to initialize the service.
 *
 * @return      NRF_SUCCESS on successful initialization of service, otherwise an error code.
 */
uint32_t ble_fizz_buzz_init(ble_fizz_buzz_t * p_fizz_buzz, const ble_fizz_buzz_init_t * p_fizz_buzz_init);













/**@brief Function for handling the Application's BLE Stack events.
 *
 * @details Handles all events from the BLE stack of interest to the Battery Service.
 *
 * @note 
 *
 * @param[in]   p_fizz_buzz      Custom Service structure.
 * @param[in]   p_ble_evt  Event received from the BLE stack.
 */
void ble_fizz_buzz_on_ble_evt( ble_evt_t const * p_ble_evt, void * p_context);

/**@brief Function for updating the custom value.
 *
 * @details The application calls this function when the cutom value should be updated. If
 *          notification has been enabled, the custom value characteristic is sent to the client.
 *
 * @note 
 *       
 * @param[in]   p_bas          Custom Service structure.
 * @param[in]   Custom value 
 *
 * @return      NRF_SUCCESS on success, otherwise an error code.
 */

uint32_t ble_fizz_buzz_fizz_buzz_value_update(ble_fizz_buzz_t * p_fizz_buzz, uint8_t fizz_buzztom_value);

#endif // BLE_FIZZ_BUZZ_H__