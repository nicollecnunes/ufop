using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.InputSystem;

public class PlayerController : MonoBehaviour
{
    private Rigidbody _rb;
    private float _moveX, _moveY, _moveZ;

    void Start()
    {
       _rb = GetComponent<Rigidbody>(); 
    }
    
    void OnMove(InputValue movementValue)
    {
    	Vector2 movementVector = movementValue.Get<Vector2>();

        _moveX = movementVector.x;
        _moveY = movementVector.y;
        _moveZ = 0.0f;
    }

    void FixedUpdate()
    {
        Vector3 movement = new Vector3(_moveX, _moveZ, _moveY);
        _rb.AddForce(movement);
    }
}
