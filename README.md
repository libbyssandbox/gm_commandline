## Functions
<details>
  <summary>boolean commandline.HasParm(string parmName)</summary>

  Returns `true` if the parm is present in the launch arguments, `false` otherwise.
  ```lua
  local bAllowLocalConnection = commandline.HasParm("-allowlocalhttp")
  ```
</details>

<details>
  <summary>string commandline.GetParmString(string parmName, string default)</summary>

  Returns the string value of the parm if present, provided default otherwise.
  ```lua
  local strName = commandline.GetParmString("-somename", "unknown")
  ```
</details>

<details>
  <summary>number commandline.GetParmNumber(string parmName, number default)</summary>

  Returns the number value of the parm if present, provided default otherwise.
  ```lua
  local iWidth = commandline.GetParmNumber("-width", 1920)
  local flDensity = commandline.GetParmNumber("-density", 4.5)
  ```
</details>
