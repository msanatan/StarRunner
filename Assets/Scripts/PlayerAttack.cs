using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.InputSystem;

public class PlayerAttack : MonoBehaviour
{
    [SerializeField]
    private GameObject laser;
    private CustomControls playerControls;
    private InputAction fire;
    private float cooldown = 0.0f;
    private float maxCooldown = 8.0f;


    private void Awake()
    {
        playerControls = new CustomControls();
        fire = playerControls.Player.Fire;
    }

    private void OnEnable()
    {
        fire.Enable();
        fire.performed += OnFire;
    }

    private void OnDisable()
    {
        fire.Disable();
        fire.performed -= OnFire;
    }

    private void OnFire(InputAction.CallbackContext context)
    {
        if (cooldown <= 0.0f)
        {
            cooldown = maxCooldown * Time.deltaTime;
            Debug.Log("Fire");
        }
        else
        {
            cooldown -= Time.deltaTime;
        }
    }
}
