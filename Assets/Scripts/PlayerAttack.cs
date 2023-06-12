using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.InputSystem;

public class PlayerAttack : MonoBehaviour
{
    [SerializeField]
    private GameObject laser;
    [SerializeField]
    float laserWaitTime = 1.0f;
    private CustomControls playerControls;
    private InputAction fire;
    private Transform leftLaserSpawnPoint;
    private Transform rightLaserSpawnPoint;
    private bool canShoot = true;


    private void Awake()
    {
        playerControls = new CustomControls();
        fire = playerControls.Player.Fire;
        leftLaserSpawnPoint = transform.Find("LeftLaserSpawnPoint");
        rightLaserSpawnPoint = transform.Find("RightLaserSpawnPoint");
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
        if (canShoot)
        {
            canShoot = false;
            var leftLaserInstance = Instantiate(laser, leftLaserSpawnPoint.position, laser.transform.rotation);
            var rightLaserInstance = Instantiate(laser, rightLaserSpawnPoint.position, laser.transform.rotation);
            leftLaserInstance.SetActive(true);
            rightLaserInstance.SetActive(true);
            leftLaserInstance.GetComponent<Rigidbody>().velocity = leftLaserSpawnPoint.forward * 12;
            rightLaserInstance.GetComponent<Rigidbody>().velocity = rightLaserSpawnPoint.forward * 12;
            StartCoroutine(EnableShoot());
        }
    }

    IEnumerator EnableShoot()
    {
        yield return new WaitForSeconds(laserWaitTime);
        canShoot = true;
    }
}
