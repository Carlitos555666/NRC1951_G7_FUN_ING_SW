<script>
// Usuarios registrados
const registeredUsers = [
  { username: "tesorero", password: "tesorero123", role: "tesorero" } // Usuario fijo para el tesorero
];

// Mostrar formulario de registro
function showRegisterForm() {
  document.getElementById("loginForm").style.display = "none";
  document.getElementById("registerForm").style.display = "block";
}

// Mostrar formulario de inicio de sesión
function showLoginForm() {
  document.getElementById("loginForm").style.display = "block";
  document.getElementById("registerForm").style.display = "none";
}

// Manejo del formulario de inicio de sesión
document.getElementById("loginForm").addEventListener("submit", function (event) {
  event.preventDefault();
  const username = document.getElementById("username").value;
  const password = document.getElementById("password").value;

  // Validar usuarios
  const user = registeredUsers.find(user => user.username === username && user.password === password);

  if (user) {
    if (user.role === "tesorero") {
      window.location.href = "https://carlitoscarloss644.wixsite.com/tierras-del-sol-2-te";
    } else {
      window.location.href = "https://carlitoscarloss644.wixsite.com/tierras-del-sol-2";
    }
  } else {
    alert("Usuario o contraseña incorrectos.");
  }
});

// Manejo del formulario de registro
document.getElementById("registerForm").addEventListener("submit", function (event) {
  event.preventDefault();
  const newUsername = document.getElementById("newUsername").value;
  const newPassword = document.getElementById("newPassword").value;

  // Evitar duplicados
  if (registeredUsers.find(user => user.username === newUsername)) {
    alert("El usuario ya existe. Por favor, elige otro nombre de usuario.");
  } else {
    // Registrar nuevo usuario como condómino
    registeredUsers.push({ username: newUsername, password: newPassword, role: "condomino" });
    alert("Registro exitoso. Ahora puedes iniciar sesión.");
    showLoginForm(); // Regresa al formulario de login
  }
});
</script>