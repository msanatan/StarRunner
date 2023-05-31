using UnityEngine;
using UnityEngine.InputSystem;

public class PlayerMovement : MonoBehaviour
{
    public float playerSpeed = 5.0f;
    private CustomControls input = null;
    private Vector3 playerVelocity = Vector3.zero;
    private Rigidbody rb = null;
    private Vector3 playerRotation = Vector3.zero;

    private void Awake()
    {
        input = new CustomControls();
        rb = GetComponent<Rigidbody>();
    }

    private void OnEnable()
    {
        input.Enable();
        input.Player.Movement.performed += OnMovementPerformed;
        input.Player.Movement.canceled += OnMovementCancelled;
    }

    private void OnDisable()
    {
        input.Disable();
        input.Player.Movement.performed -= OnMovementPerformed;
        input.Player.Movement.canceled -= OnMovementCancelled;
    }

    private void OnMovementPerformed(InputAction.CallbackContext value)
    {
        playerVelocity = value.ReadValue<Vector3>();
    }

    private void OnMovementCancelled(InputAction.CallbackContext value)
    {
        playerVelocity = Vector3.zero;
    }

    private void FixedUpdate()
    {
        rb.velocity = playerVelocity.normalized * playerSpeed;
    }

    private void Update()
    {
        playerRotation.x = rb.velocity.y / 2;
        playerRotation.y = -rb.velocity.x / 2;
        playerRotation.z = -rb.velocity.x * 2;
        transform.Rotate(playerRotation * Time.deltaTime);
    }
}
