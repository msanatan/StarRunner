using UnityEngine;
using UnityEngine.InputSystem;

public class PlayerMovement : MonoBehaviour
{
    [SerializeField]
    private float playerSpeed = 10.0f;
    [SerializeField]
    private float xRange = 12.0f;
    [SerializeField]
    private float yRange = 7.0f;
    [SerializeField]
    private float positionPitchFactor = -2f;
    [SerializeField]
    private float positionYawFactor = 2f;
    [SerializeField]
    private float controlPitchFactor = -10f;
    [SerializeField]
    private float controlRollFactor = -20f;
    private CustomControls input = null;
    private float xThrow;
    private float yThrow;
    private Vector3 playerVelocity = Vector3.zero;
    private Vector3 playerPosition = Vector3.zero;
    private Vector3 clampedPosition = Vector3.zero;


    private void Awake()
    {
        input = new CustomControls();
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
        xThrow = value.ReadValue<Vector3>().x;
        yThrow = value.ReadValue<Vector3>().y;
    }

    private void OnMovementCancelled(InputAction.CallbackContext value)
    {
        xThrow = 0f;
        yThrow = 0f;
    }

    private void ProcessTranslation()
    {
        playerVelocity.x = xThrow;
        playerVelocity.y = yThrow;
        playerPosition = transform.position + (playerVelocity * playerSpeed * Time.deltaTime);
        clampedPosition.x = Mathf.Clamp(playerPosition.x, -xRange, xRange);
        clampedPosition.y = Mathf.Clamp(playerPosition.y, -yRange, yRange);
        clampedPosition.z = playerPosition.z;
        transform.position = clampedPosition;
    }

    private void ProcessRotation()
    {
        float pitchDueToPosition = transform.position.y * positionPitchFactor;
        float pitchDueToControlThrow = yThrow * controlPitchFactor;

        float pitch = pitchDueToPosition + pitchDueToControlThrow;
        float yaw = transform.position.x * positionYawFactor;
        float roll = xThrow * controlRollFactor;

        transform.rotation = Quaternion.Euler(pitch, yaw, roll);

    }

    private void Update()
    {
        ProcessTranslation();
        ProcessRotation();
    }
}
