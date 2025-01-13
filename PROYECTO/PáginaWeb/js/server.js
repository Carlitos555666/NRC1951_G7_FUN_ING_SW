const express = require('express');
const bodyParser = require('body-parser');

const app = express();
app.use(bodyParser.json());
app.use(express.static('public')); // Cambia 'public' por la carpeta donde está tu login.html

// Ruta para procesar el login
app.post('/login', (req, res) => {
  const { username, password } = req.body;

  // Validar credenciales
  if (username === 'admin' && password === '1234') {
    res.send('Login exitoso');
  } else {
    res.status(401).send('Credenciales incorrectas');
  }
});

// Inicia el servidor
const PORT = 3000; // Cambia el puerto si es necesario
app.listen(PORT, () => {
  console.log(`Servidor corriendo en http://localhost:${PORT}`);
});
