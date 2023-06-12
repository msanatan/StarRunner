using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerLaserController : MonoBehaviour
{
    [SerializeField]
    private float maxDistance = 50.0f;
    private Vector3 initialPosition = Vector3.zero;

    // Update is called once per frame
    private void Update()
    {
        if (Vector3.Distance(transform.position, initialPosition) > maxDistance)
        {
            Destroy(gameObject);
        }
    }
}
