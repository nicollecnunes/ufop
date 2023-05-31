using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.InputSystem;
using TMPro;

public class PlayerController : MonoBehaviour
{
    public float speed = 0;
    public TextMeshProUGUI countText;

    private Rigidbody _rb;
    private int  _count;
    private float _moveX, _moveY, _moveZ;

    void Start()
    {
       _rb = GetComponent<Rigidbody>(); 
       _count = 0;

       SetCountText();
    }
    
    void OnMove(InputValue movementValue)
    {
    	Vector2 movementVector = movementValue.Get<Vector2>();

        _moveX = movementVector.x;
        _moveY = movementVector.y;
        _moveZ = 0.0f;
    }

    void SetCountText()
    {
        countText.text = "Count: " + _count.ToString();
    }

    void FixedUpdate()
    {
        Vector3 movement = new Vector3(_moveX, _moveZ, _moveY);
        _rb.AddForce(movement * speed);
    }

    private void OnTriggerEnter(Collider other)
    {
        if(other.gameObject.CompareTag("Pickup"))
        {
            other.gameObject.SetActive(false);
            _count = _count + 1;
            SetCountText();
        }

    }
}
